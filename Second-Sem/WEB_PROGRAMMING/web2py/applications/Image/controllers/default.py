def index():
    images = db().select(db.image.ALL, orderby=db.image.title)
    return dict(images=images)

def show():
    image = db(db.image.id==request.args(0)).select()[0]
    form = SQLFORM(db.comment)
    form.vars.image_id = image.id
    if form.accepts(request.vars, session):
        response.flash = 'your comment is posted'
    comments = db(db.comment.image_id==image.id).select()
    return dict(image=image, comments=comments, form=form)

def download():
    return response.download(request, db)
