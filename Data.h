#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <string.h>
#include <iomanip>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <stdlib.h>     
#include <time.h>
#include <fstream>
#include "User.h"
#include "Reviews.h"


using namespace std;

class Data {

private:

public:
	Data();
	~Data();

	void add_review(Reviews new_rev);
	void add_user(string id, string pwd);
	void add_follower(string usr, string flrID);
	void add_following(string usr, string flngID);
	void update_pwd(string usr, string pwd);
	//void update_followers(vector<User> *all_users);
	//void update_following(vector<User> *all_users);
	//void set_all_reviews(vector<Reviews> all_reviews);

	vector<Reviews> get_all_reviews();
	vector<User> get_all_users();





};


#endif 

