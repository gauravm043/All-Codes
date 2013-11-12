def index():
	images=db().select(db.image.ALL,orderby=db.image.title)
	return dict(images=images)
def show():
	image=db(db.image.id==request.args(0)).select().first()
	db.comment.image_id.default=image.id
	form=SQLFORM(db.comment)
	if form.process().accepted:
			response.flash='your comment is posted'
	comment=db(db.comment.image_id==image.id).select()
	return dict(image=image,comment=comment,form=form)
def download():
	return response.download(request,db)
