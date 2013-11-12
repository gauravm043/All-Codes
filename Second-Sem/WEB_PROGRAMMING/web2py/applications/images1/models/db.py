db=DAL("sqlite://storage.sqlite")
db.define_table('image',
				db.Field('title','string',unique=True),
				db.Field('file', 'upload'))
db.define_table('comment',
				db.Field('image_id',db.image),
				db.Field('author','string'),
				db.Field('email','string'),
				db.Field('body','text'))
db.comment.image_id.requires=IS_IN_DB(db,db.image.id,'db.image.title')
db.comment.author.requires=IS_NOT_EMPTY()
db.comment.email.requires=IS_EMAIL()
db.comment.body.requires=IS_NOT_EMPTY()
db.comment.image_id.writable=db.comment.image_id.readable=False
