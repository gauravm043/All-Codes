




# -*- coding: utf-8 -*-
# this file is released under public domain and you can use without limitations

#########################################################################
## This is a samples controller
## - index is the default action of any application
## - user is required for authentication and authorization
## - download is for downloading files uploaded in the db (does streaming)
## - call exposes all registered services (none by default)
#########################################################################


def index():
    """
    example action using the internationalization operator T and flash
    rendered by views/default/index.html or views/generic.html

    if you need a simple wiki simple replace the two lines below with:
    return auth.wiki()
    """
    response.flash = T("Welcome to web2py!")
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




def select():
     if(request.post_vars['name']=='1'):
	  redirect(URL('que_1'))
     if(request.post_vars['name']=='4'):
	  redirect(URL('que_4'))
     if(request.post_vars['name']=='2'):
	  redirect(URL('que_2'))
     if(request.post_vars['name']=='3'):
	  redirect(URL('que_3'))
     if(request.post_vars['name']=='5'):
	  redirect(URL('que_5'))
import datetime
def que_1():
     return locals()

def ans():
     m={}
     s={}
     p={}
     pos=request.post_vars['name']
     k=db(db.artist.id==pos).select(db.artist.profession,db.artist.name)
     if(k[0]['profession']=='Actor'):
	  m=db((db.artist.id==pos)&(db.artist.id==db.movie.hero)).select(db.movie.name)
     if(k[0]['profession']=='Director'):
	  m=db((db.artist.id==pos)&(db.artist.name==db.movie.director)).select(db.movie.name)
     if(k[0]['profession']=='Singer'):
	  s=db((db.artist.id==pos)&(db.artist.name==db.song.singer)).select(db.song.name)
     return dict(k=k,m=m,s=s)
	  

    
def que_2():
     k=db((db.song.singer=='Balu')).select(db.song.name)
     return dict(k=k)

def que_3():
     ans=db((db.song.singer=='Balu')&(db.song.movie=='Sankarabharanam')).select(db.song.name)
     return dict(ans=ans)

def que_4():
     k=db((db.song.singer=='Balu')&(db.song.movie==db.movie.name)&(db.movie.release_date<datetime.date(2000,1,1))).select(db.song.name,db.song.singing_actor)
     return dict(k=k)
def que_5():
     k=db((db.rating.rating>=4)&(db.rating.song==db.song.id)).select(db.song.name,db.song.singer)
     return dict(k=k)
