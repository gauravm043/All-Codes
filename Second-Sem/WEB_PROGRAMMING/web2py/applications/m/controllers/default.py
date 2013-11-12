# -*- coding: utf-8 -*-
# this file is released under public domain and you can use without limitations

#########################################################################
## This is a samples controller
## - index is the default action of any application
## - user is required for authentication and authorization
## - download is for downloading files uploaded in the db (does streaming)
## - call exposes all registered services (none by default)
#########################################################################


@auth.requires_login()
def index():
    """
    example action using the internationalization operator T and flash
    rendered by views/default/index.html or views/generic.html

    if you need a simple wiki simple replace the two lines below with:
    return auth.wiki()
    """
    response.flash = T("Online Examination")
    if(auth.user):
	 db(auth.user.email==db.student.email).update(coun=1)
    return dict(message=T('Hello World'))
   


def user():
    """
    exposes:
    http://..../[app]/default/user/login
    http://..../[app]/default/user/logout
    http://..../[app]/default/user/register
    http://..../[app]/default/user/profile
    http://..../[app]/default/user/retrieve_password
    http://..../[app]/default/user/change_password
    use @auth.requires_login()
        @auth.requires_membership('group name')
        @auth.requires_permission('read','table name',record_id)

    to decorate functions that need access control
    """
    return dict(form=auth())


def download():
    """
    allows downloading of uploaded files
    http://..../[app]/default/download/[filename]
    """
    return response.download(request, db)


def call():
    """
    exposes services. for example:
    http://..../[app]/default/call/jsonrpc
    decorate with @services.jsonrpc the functions to expose
    supports xml, json, xmlrpc, jsonrpc, amfrpc, rss, csv
    """
    return service()


@auth.requires_signature()
def data():
    """
    http://..../[app]/default/data/tables
    http://..../[app]/default/data/create/[table]
    http://..../[app]/default/data/read/[table]/[id]
    http://..../[app]/default/data/update/[table]/[id]
    http://..../[app]/default/data/delete/[table]/[id]
    http://..../[app]/default/data/select/[table]
    http://..../[app]/default/data/search/[table]
    but URLs must be signed, i.e. linked with
      A('table',_href=URL('data/tables',user_signature=True))
    or with the signed load operator
      LOAD('default','data.load',args='tables',ajax=True,user_signature=True)
    """
    return dict(form=crud())





#---------------------------------------------------Project Starts---------------------------------------------------------------#

@auth.requires_login()
def student_info():
     a=auth.user.email
     b=auth.user.first_name
     c=auth.user.last_name
     response.flash='Logged in as '+b+' '+c
     form=SQLFORM(db.student)
     form.vars.email=a
     if (form.accepts(request,session)):
	  response.flash="Personal Information Successfully Added"
     return dict(form=form)

@auth.requires_login()
@auth.requires_membership('IIIT_FACULTY_DEPARTMENT')
def set_paper():
     form=SQLFORM(db.questions)
     form.vars.faculty_id=auth.user.email
     if form.accepts(request,session):
	  response.flash="Question Inserted"
     return dict(form=form)


@auth.requires_login()
def exam():
     CHECK_TEACHER=db((auth.user.id==db.auth_membership.user_id)&(db.auth_membership.group_id==17)).select(db.auth_user.ALL)
     p={}
     x=db(db.see.id==8).select(db.see.course)
     x=x[0]['course']
     k=db(auth.user.email==db.student.email).select(db.student.email)
     if k:
          p=db(auth.user.email==db.student.email).select(db.student.coun)
          n=p[0]['coun']
          que={}
          que=db((db.questions.course==x)&(db.questions.que_number==n)).select(db.questions.que_number,
	       				            db.questions.question,
					            db.questions.option_a,
	                                            db.questions.option_b,
	                                            db.questions.option_c,
	                                            db.questions.option_d,
	  				            )
          if (db((auth.user.id==db.auth_membership.user_id)&(db.auth_membership.group_id==17)).select(db.auth_user.ALL)):
	       form=SQLFORM.factory(
			 Field('ans',requires=IS_IN_SET(['A','B','C','D'],multiple=True),widget=SQLFORM.widgets.checkboxes.widget),
			 Field('com','text'))
			      
			 
	       
	  else:
	       form=SQLFORM.factory(
			 Field('ans',requires=IS_IN_SET(['A','B','C','D'],multiple=True),widget=SQLFORM.widgets.checkboxes.widget
			      )
			 )
	  check=db((auth.user.email==db.answer.stid)&(n==db.answer.que_num)&(db.see.course==db.answer.course)).select(db.answer.ALL)
	  if(form.accepts(request,session)):
	       response.flash="Answer Submitted"
	       if check:
		    db((auth.user.email==db.answer.stid)&(n==db.answer.que_num)&(x==db.answer.course)).update(op= form.vars.ans,course=x)
	       else:
		    db.answer.insert(que_num=n,stid=auth.user.email,op=form.vars.ans,course=x)
	       response.flash=str(form.vars.ans)+"asdasd"
	       if CHECK_TEACHER:
		    if(form.vars.com):
			 db.comments.insert(faculty_id=auth.user.email,que=n,course=x,comment_given=form.vars.com)
	     
	       redirect('next')

     if k:
	  if que:
	       if CHECK_TEACHER:
		    com=db((db.comments.que==n)&(db.comments.course==x)).select(db.comments.comment_given)
		    return dict(que=que,form=form,com=com)
	       else:
		    com={}
		    return dict(que=que,form=form,com=com)

	  else:
	       redirect(URL('default','show'))
     else:
	  redirect(URL('default','student_info'))
	  


@auth.requires_login()
def next():
     p=db(auth.user.email==db.student.email).select(db.student.coun)
     x=db(db.see.id==8).select(db.see.course)
     x=x[0]['course']
     n=p[0]['coun']
     correct=db((db.questions.que_number==n)&(db.questions.course==x)).select(db.questions.ans)
     given=db((db.answer.stid==auth.user.email)&(db.answer.que_num==n)&(db.answer.course==x)).select(db.answer.op)
     print given[0]['op']
     if given and given[0]['op']!='||':
	  print 'aaaaa'
	  if(given!=None and correct[0]['ans']==given[0]['op']):
	       db(db.questions.que_number==n).update(stid=auth.user.email)
	       db((db.questions.stid==auth.user.email)&(db.questions.que_number==n)).update(obtained_marks=4)
	  elif(correct!=given and given!=None):
	       db(db.questions.que_number==n).update(stid=auth.user.email)
	       db((db.questions.stid==auth.user.email)&(db.questions.que_number==n)).update(obtained_marks=-1)
     
     db(auth.user.email==db.student.email).update(coun=n+1)
     que=db(db.questions.que_number>0).select(db.questions.que_number)
     redirect(URL('default','exam'))


def prev():
     p=db(auth.user.email==db.student.email).select(db.student.coun)
     n=p[0]['coun']
     if(n-1>0):
	  db(auth.user.email==db.student.email).update(coun=n-1)
     if(n-1>0):
	  redirect(URL('default','exam'))
     else:
	  redirect(URL('default','exam'))
def courses():
     return locals()
def noq():
     return locals()

def list():
     k=db((db.auth_membership.user_id==db.auth_user.id)&(db.auth_membership.group_id!=17)).select(db.auth_user.first_name,db.auth_user.last_name)
     return dict(k=k)


def faculty():
     f=db((db.auth_membership.user_id==db.auth_user.id)&(db.auth_membership.group_id==17)).select(db.auth_user.first_name,db.auth_user.last_name)
     return dict(f=f)

def show():
     x=db(db.see.id==8).select(db.see.course)
     x=x[0]['course']
     a=auth.user.email
     k=db((db.questions.stid==a)&(db.questions.course==x)).select(db.questions.obtained_marks)
     marks=0
     for i in range(len(k)):
	  marks=marks+k[i]['obtained_marks']
     db(auth.user.email==db.student.email).update(final_marks=marks,given=0)
     return dict(marks=marks)
     if (db((auth.user.id==db.auth_membership.user_id)&(db.auth_membership.group_id==17)).select(db.auth_user.ALL)):
	  print'wallah'

def give_exam():
     return locals()

def which_one():
     p=request.post_vars['id']
     db(db.see.id==8).update(course=p)
     redirect(URL('exam'))

@auth.requires_login()
def show_paper():
     if (db((auth.user.id==db.auth_membership.user_id)&(db.auth_membership.group_id==17)).select(db.auth_user.ALL)):
	  query=db(db.questions.faculty_id==auth.user.email).select(db.questions.ALL)	  
	  grid=SQLFORM.grid(db.questions)
	  return locals()
     else:
	  query=db(db.answer.stid==auth.user.email).select(db.answer.ALL)	  
	  grid=SQLFORM.grid(db.answer,editable=False,deletable=False)
	  return locals()

def set_time():
     form=SQLFORM(db.times)
     if (form.accepts(request,session)):
	  response.flash="Time Setted"
     return dict(form=form)
