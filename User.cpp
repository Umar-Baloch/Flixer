#include "User.h"

using namespace std;


User::User(){}

//overloaded constructer
User::User(string id, string pwd){
	this->ID = id;
	this->PWD = pwd;
}

User::~User(){}

void User::set_id(string id){
	this->ID = id;
}

void User::set_pwd(string pwd){
	this->PWD = pwd;
}

//saves all followers of the user in a string vector
void User::set_followers(string flrs){
	istringstream ss(flrs);
	string token;

	while(getline(ss, token, ',')) {
	    this->Followers.push_back(token);
	}
}

//saves all of the users we are following in a string vector
void User::set_following(string flngs){
	istringstream ss(flngs);
	string token;

	while(getline(ss, token, ',')) {
	    this->Following.push_back(token);
	}
}

//function to call when some user unfollows us
void User::remove_follower(string flr){
	int foundAt;
	for(int i = 0; i != Followers.size(); i++){
		if(Followers[i] == flr){
			foundAt = i;
		}
	}

	Followers.erase (Followers.begin()+foundAt);
}

//function to call when we unfollows some user
void User::remove_following(string flng){
	int foundAt;
	for(int i = 0; i != Following.size(); i++){
		if(Following[i] == flng){
			foundAt = i;
		}
	}

	Following.erase (Following.begin()+foundAt);
}

void User::add_follower(string flr){
	this->Followers.push_back(flr);
}

void User::add_following(string flng){
	this->Following.push_back(flng);
}

string User::get_id(){
	return this->ID;
}

string User::get_pwd(){
	return this->PWD;
}

vector<string> User::get_followers(){
	return this->Followers;
}

vector<string> User::get_following(){
	return this->Following;
}



