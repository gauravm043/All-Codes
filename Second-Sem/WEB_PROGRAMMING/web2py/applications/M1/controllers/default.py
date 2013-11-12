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
     if(request.post_vars['name']=='2'):
	  redirect(URL('que_2'))
     if(request.post_vars['name']=='3'):
	  redirect(URL('que_3'))
     if(request.post_vars['name']=='5'):
	  redirect(URL('que_5'))
def que_1():
     k=db((db.artist.id==8)&(db.artist.id==db.song.singer)).select(db.song.name)
     return dict(k=k)

def que_2():
     k=db((db.artist.singers=='balu')&(db.artist.id==db.song.singer)).select(db.song.name)
     return dict(k=k)

def que_3():
     ans=db((db.artist.singers=='balu')&(db.artist.id==db.song.singer)&(db.movie.name=='Shankarabharanam')).select(db.song.name)
     return dict(ans=ans)
def que_5():
     k=db((db.rating.rating>4)&(db.rating.song==db.song.id)&(db.song.singer==db.artist.id)).select(db.song.name,db.artist.singers)
     return dict(k=k)