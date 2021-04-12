#include"Data.h"
#include "User.h"
#include "Reviews.h"

using namespace std;


Data::Data(){}

Data::~Data(){}

//function to add new review to data file
void Data::add_review(Reviews new_rev){
	ofstream myfile;
  	myfile.open ("Reviews-Data.txt", fstream::app);
  	myfile << new_rev.get_posted_by() << "|" <<
  		new_rev.get_movie() << "|" << new_rev.get_body() <<
  		"|" << new_rev.get_time() << "\n";
  	
  	myfile.close();
}

//********************************************************************************************************
//********************************************************************************************************

//function to add new user to data files
void Data::add_user(string id, string pwd){
	ofstream myfile;
  	myfile.open ("User-Data.txt", fstream::app);
  	myfile << id << "," << pwd << ",";
  	myfile.close();

  	myfile.open ("Follower-Data.txt", fstream::app);
  	myfile << id << ",\n";
  	myfile.close();

  	myfile.open ("Following-Data.txt", fstream::app);
  	myfile << id << ",\n";
  	myfile.close();

}

//********************************************************************************************************
//********************************************************************************************************

//function to add usr in follower data file when they follow you
//this is done by reading in data from one file to another and adding usr string in the right place 
void Data::add_follower(string usr, string flrID){
	ofstream o;
	ifstream i;
	string line;
	string currentusr;

	o.open("temp.txt");
	i.open("Follower-Data.txt");

	if (o.fail()|| i.fail()) {
		cout << "Something went wrong1" << endl;
	}

	while (!(i.eof())) {
		getline(i, currentusr, ',');
		getline(i, line, '\n');

		if(currentusr.length() != 0){
			if(currentusr == usr){
				if(line.length() > 1){
					o << currentusr << "," << flrID << "," << line <<"\n";
				}
				else{
					o << currentusr << "," << flrID <<"\n";
				}
			}

			else if(line.length() > 1){
				o << currentusr << "," << line <<"\n";
			}

			else{
				o << currentusr << ",\n";
			}
		}
	}
	o.close();
	i.close();

	if (remove("Follower-Data.txt") != 0)
		perror("Error removing file");

	if (rename("temp.txt", "Follower-Data.txt") != 0)
		perror("Error renaming file");
}

//function to add usr in following data file when you follow them
//this is done by reading in data from one file to another and adding usr string in the right place 
void Data::add_following(string usr, string flngID){
	ofstream o;
	ifstream i;
	string line;
	string currentusr;

	o.open("temp.txt");
	i.open("Following-Data.txt");

	if (o.fail()|| i.fail()) {
		cout << "Something went wrong1" << endl;
	}

	while (!(i.eof())) {
		getline(i, currentusr, ',');
		getline(i, line, '\n');

		if(currentusr.length() != 0){
			if(currentusr == usr){
				if(line.length() > 1){
					o << currentusr << "," << flngID << "," << line <<"\n";
				}
				else{
					o << currentusr << "," << flngID <<"\n";
				}
			}

			else if(line.length() > 1){
				o << currentusr << "," << line <<"\n";
			}

			else{
				o << currentusr << ",\n";
			}
		}
	}
	o.close();
	i.close();

	if (remove("Following-Data.txt") != 0)
		perror("Error removing file");

	if (rename("temp.txt", "Following-Data.txt") != 0)
		perror("Error renaming file");
}

//********************************************************************************************************
//********************************************************************************************************

//function to update password in data file
void Data::update_pwd(string usr, string pwd){
	ofstream o;
	ifstream i;
	string line;
	string currentusr;

	o.open("temp.txt");
	i.open("User-Data.txt");

	if (o.fail()|| i.fail()) {
		cout << "Something went wrong1" << endl;
	}

	while (!(i.eof())) {
		getline(i, currentusr, ',');
		getline(i, line, ',');

		if(currentusr.length() != 0){
			if(currentusr == usr){
				o << currentusr << "," << pwd <<",";
			}

			else if(line.length() > 0){
				o << currentusr << "," << line <<",";
			}
		}
	}
	o.close();
	i.close();

	if (remove("User-Data.txt") != 0)
		perror("Error removing file");

	if (rename("temp.txt", "User-Data.txt") != 0)
		perror("Error renaming file");
}
/*

//incorrect extra functions that can be changed later to add more functionality
void Data::update_followers(vector<User> *all_users){
	vector<string> flrs;

	ofstream myfile;
	myfile.open("Follower-Data.txt", ios::out);

	if(myfile.fail()){
		cout << "Something went wrong!";
	}

	for(int i = 0; i != (*all_users).size(); i++){
		flrs = all_users->at(i).get_followers();
		myfile << all_users->at(i).get_id() << ",";

		for(int j = 0; j!= flrs.size(); j++){
			if(j = 0){
				myfile << flrs[j];
			}
			else{
				myfile << "," << flrs[j];
			}
		}
		myfile << "\n";
	}
	myfile.close();
}

void Data::update_following(vector<User> *all_users){
	vector<string> flng;

	ofstream myfile;
	myfile.open("Following-Data.txt", ios::out);

	if(myfile.fail()){
		cout << "Something went wrong!";
	}

	cout << "I'm Here";
	for(int i = 0; i != (*all_users).size(); i++){
		flng = all_users->at(i).get_followers();
		myfile << all_users->at(i).get_id() << ",";

		cout << "I'm Here2";
		for(int j = 0; j!= flng.size(); j++){
			if(j = 0){
				myfile << flng[j];
			}
			else{
				myfile << "," << flng[j];
			}
		}
		myfile << "\n";
	}
	myfile.close();
}
function to update data-reviews file
void Data::set_all_reviews(vector<Reviews> all_reviews){
	ofstream myfile;
  	myfile.open ("Reviews-Data.txt");

  	cout << all_reviews.size() << endl;

  	for(int i = 0; i != all_reviews.size(); i++){
  		myfile << all_reviews[i].get_posted_by() << "|" <<
  		all_reviews[i].get_movie() << "|" << all_reviews[i].get_body() <<
  		"|" << all_reviews[i].get_time() << "\n";
  	}
  	
  	myfile.close();
}*/

//********************************************************************************************************
//********************************************************************************************************

//function to read all reviews from data file
vector<Reviews> Data::get_all_reviews(){

	vector<Reviews> all_reviews;
	ifstream i;

	i.open("Reviews-Data.txt", ios::in);

	if (i.fail()) {
		cout << "Something went wrong" << endl;
	}

	while (!(i.eof())) {
		string movie;
		string body;
		string time;
		string posted_by;

		getline(i, posted_by, '|');
		getline(i, movie, '|');
		getline(i, body, '|');
		getline(i, time, '\n');

		if(posted_by.length() > 1 && time.length() > 1){
			Reviews nwrvw(posted_by);
		
			nwrvw.set_movie(movie);
			nwrvw.set_body(body);
			nwrvw.set_time(time);

			all_reviews.push_back(nwrvw);
		}

	}

	i.close();

	return all_reviews;
}

//********************************************************************************************************
//********************************************************************************************************


//function to read all users info from data file
vector<User> Data::get_all_users(){
	vector<User> all_users;
	ifstream i;
	ifstream flrs;
	ifstream flng;

	i.open("User-Data.txt", ios::in);

	if (i.fail()) {
		cout << "Something went wrong1" << endl;
	}

	while (!(i.eof())) {
		string id;
		string pwd;

		getline(i, id, ',');
		getline(i, pwd, ',');

		User nwusr;
		nwusr.set_id(id);
		nwusr.set_pwd(pwd);

		all_users.push_back(nwusr);
	}

	i.close();

	flrs.open("Follower-Data.txt", ios::in);
	if (flrs.fail()) {
		cout << "Something went wrong2" << endl;
	}

	while (!(flrs.eof())) {
		string id;
		string followers;

		getline(flrs, id, ',');
		getline(flrs, followers, '\n');

		if(followers.length() > 0){
			for(int i = 0; i != all_users.size(); i++){
				if(all_users[i].get_id() == id){
					all_users[i].set_followers(followers);
				}
			}
		}	
	}

	flrs.close();

	flng.open("Following-Data.txt", ios::in);
	if (flng.fail()) {
		cout << "Something went wrong3" << endl;
	}

	while (!(flng.eof())) {
		string id;
		string following;

		getline(flng, id, ',');
		getline(flng, following, '\n');

		if(following.length()){
			for(int i = 0; i != all_users.size(); i++){
				if(all_users[i].get_id() == id){
					all_users[i].set_following(following);
				}
			}
		}	
	}

	flng.close();

	return all_users;
}