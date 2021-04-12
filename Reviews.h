#ifndef REVIEWS_H
#define REVIEWS_H

#include <iostream>
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


using namespace std;

class Reviews {

private:
	string Movie;
	string Body;
	string Posted_by;
	string Time;

public:

	Reviews(string posted_by);
	~Reviews();


	void set_movie(string movie);
	void set_body(string body);
	void set_time(string tm);

	string get_movie();
	string get_body();
	string get_time();
	string get_posted_by();

};


#endif 

