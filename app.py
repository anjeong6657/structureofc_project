
from flask import Flask 
from flask_sqlalchemy import SQLAlchemy # project module 
from route.info_route import info_route 
app = Flask(__name__) ##db info setting 
app.config["SQLALCHEMY_DATABASE_URI"] = "mysql+pymysql://yurim:tmemvmajrrjfl@sdp-1.cw0d5ase2oqv.ap-northeast-2.rds.amazonaws.com/sdpdb_1"

app.config["SQLALCHEMY_TRACK_MODIFICATIONS"] = False 

 
db = SQLAlchemy() 
db.init_app(app) 
app.register_blueprint(info_route) 

if __name__ == '__main__': 
    app.run(debug=True)

