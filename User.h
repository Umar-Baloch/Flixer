#ifndef USER_H
#define USER_H

#include <iostream>
#include <cmath>
#include <ctime>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <stdlib.h>     
#include <time.h>
#include <fstream>
#include "Reviews.h"

using namespace std;

class User {

private:
	string ID;
	string PWD;
	vector<string> Followers;
	vector<string> Following;

public:
	User();
	User(string id, string pwd); //should also construct overload constrcter that creates user with ID and pwd
	//Destructor
	~User();

	void set_id(string id);
	void set_pwd(string pwd);
	void set_followers(string flrs);
	void set_following(string flngs);
	void add_follower(string flr);
	void add_following(string flng);
	void remove_follower(string flr);
	void remove_following(string flng);
	
	
	string get_id();
	string get_pwd();
	vector<string> get_followers();
	vector<string> get_following();
	
	


};

#endif