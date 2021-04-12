#include "Reviews.h"

using namespace std;



Reviews::Reviews(string posted_by){
	Posted_by = posted_by;
}

Reviews::~Reviews(){}

void Reviews::set_movie(string movie){
	Movie = movie;
}

void Reviews::set_body(string body){
	Body = body;
}

void Reviews::set_time(string tm){
	
	this->Time = tm;
}

string Reviews::get_movie(){
	return Movie;
}

string Reviews::get_body(){
	return Body;
}

string Reviews::get_time(){
	return Time;
}

string Reviews::get_posted_by(){
	return Posted_by;
}