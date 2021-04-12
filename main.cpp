#include"Reviews.h"
#include"User.h"
#include"Data.h"


using namespace std;

//function declerations
void update_following(int choice, string usr,int i, vector<User> *all_users, vector<Reviews> *all_reviews);
string change_pwd();
string current_time();

int main(){

	Data db; //initialize data IO class
	vector<User> all_users;
	vector<Reviews> all_reviews;
	

	//get all users and reviews from data files
	all_users = db.get_all_users();
	all_reviews = db.get_all_reviews();
	
	int select = 100;

//********************************************************************************************************
//********************************************************************************************************
	
	//Menu Level 1
	while(select != 3){ 
		cout << endl << "(1)- Sign-Up" << endl << "(2)- Login " << endl << "(3)- Exit " << endl << endl;
		cout << "Choose Option (1, 2, 3): ";

		cin >> select;

//********************************************************************************************************
//********************************************************************************************************

		//User Dashboard
		if(select == 2){
			cout << endl;
			string user_id;
			string user_pwd;
			string correct_pwd;
	
			cout << "Enter Email: ";
			cin >> user_id;

			bool found = false;
			for (unsigned int i = 0; i != all_users.size(); i++) {
				if(user_id == all_users[i].get_id()){
					found = true;
					correct_pwd = all_users[i].get_pwd();

					cout << "Enter Password: ";
					cin >> user_pwd;

					while(user_pwd != correct_pwd){
						cout << "Incorrect Password! \n\nEnter Password: ";
						cin >> user_pwd;
					}
					if(user_pwd == correct_pwd){ //login user if correct credentials are entered

						//Menu Level 2
						while(select != 9){ 
							cout << endl << "(1) - Change Password" << endl << "(2) - Review Feed" << 
									endl << "(3) - My Reviews" << endl;
							cout << "(4) - Add Review" << endl << "(5) - Search User" << endl << "(6) - Explore" << endl;
							cout << "(7) - Followers" << endl << "(8) - Following" << endl;
							cout << "(9) - Logout" << endl << endl;
		
							cout << "Choose Option (1 - 9): ";
							cin >> select;

							//********************************************************************************************************
							//********************************************************************************************************

							//change user password
							if(select == 1){
								string new_pwd = change_pwd();
								all_users[i].set_pwd(new_pwd);
								db.update_pwd(all_users[i].get_id(), new_pwd);
								cout << endl << "Password Changed!" << endl;
							}

							//********************************************************************************************************
							//********************************************************************************************************

							//view posts of users you follow and your posts
							if(select == 2){
								vector<string> flng = all_users[i].get_following();

								for(unsigned int j = 0; j != flng.size(); j++){
									
									//displays reviews in chronological order since the newest reviews are at the end of vector
									for(int k = all_reviews.size() - 1; k!= -1; k--){	
										if(flng[j] == all_reviews[k].get_posted_by()){
											cout << "Posted by: " + all_reviews[k].get_posted_by() << endl <<
												"Movie: " + all_reviews[k].get_movie() << endl <<
												"Review: " + all_reviews[k].get_body() << endl <<
												"Posted at: " + all_reviews[k].get_time() << endl << endl;
										}
									}
								}

								for(int j = all_reviews.size() - 1; j!= -1; j--){
									if(all_reviews[j].get_posted_by() == all_users[i].get_id()){
										cout << "Posted by: " + all_reviews[j].get_posted_by() << endl <<
												"Movie: " + all_reviews[j].get_movie() << endl <<
												"Review: " + all_reviews[j].get_body() << endl <<
												"Posted at: " + all_reviews[j].get_time() << endl << endl;
									}
								} 

							}

							//********************************************************************************************************
							//******************************************************************************************************** 

							//view your posts or delete a post
							if(select == 3){
								//int option;
								int count = 1;

								for(int j = all_reviews.size() - 1; j!= -1; j--){
									if(all_reviews[j].get_posted_by() == all_users[i].get_id()){
										cout << endl <<  count << ". Movie: " + all_reviews[j].get_movie() << endl <<
												"Review: " + all_reviews[j].get_body() << endl <<
												"Posted at: " + all_reviews[j].get_time() << endl ;
										count++;
									}
								} 


								//EXTRA FUNCTIONALITY THAT CAN BE EDITED TO ADD EDIT/DELETE REVIEW OPTIONS
								/*cout << endl << "(1). Delete a Review" << endl <<
										"(2). Go Back\n" << endl << "choose option (1 - 2): ";
								
								cin >> option;

								switch(option){
									case 1: {
										int sel;
										int ct = 1;
										int location;
										cout << endl << "Enter review number you want to delete: ";
										cin >> sel;

										for(unsigned int j = 0; j != all_reviews.size(); j++){
											if(all_reviews[j].get_posted_by() == all_users[i].get_id()){
												if(ct == sel){
													location = j;
												}
												ct++;
											}
										} 

										cout << all_reviews.size() << endl;
										all_reviews.erase(all_reviews.begin() + location);
										cout << all_reviews.size() << endl;
										db.set_all_reviews(all_reviews);

										break;}

									case 2: //go back function
										break;
								}*/
							}

							//********************************************************************************************************
							//********************************************************************************************************


							//Add new review to your posts
							if(select == 4){
								Reviews newRev(all_users[i].get_id());
								string mov;
								string rev;

								cout << endl << "Enter Movie Title: ";
								cin.ignore();
    							getline(cin, mov, '\n');

								cout << "Enter Your Review: ";
    							getline(cin, rev, '\n');

    							string time = current_time();

								newRev.set_movie(mov);
								newRev.set_body(rev);
								newRev.set_time(time); 

								all_reviews.push_back(newRev);
								db.add_review(newRev);

								cout << endl << "New Review Posted!" << endl;
							}

							//********************************************************************************************************
							//********************************************************************************************************

							//search a user and follow or view their posts 
							if(select == 5){
								string srchID;
								int opt;
								bool exists;
								vector<string> flng = all_users[i].get_following();
								
								cout << "\nEnter User Email for search: ";
								cin >> srchID;

								for(int j = 0; j != all_users.size(); j++){
									if(srchID == all_users[j].get_id()){
										bool amflng = false;
										string usr = srchID;
										for(int j = 0; j!= flng.size(); j++){
											if(usr == flng[j]){
												amflng = true;
											}
										}

										if(amflng){
											update_following(2, usr, i, &all_users, &all_reviews);
										}
										else{
											update_following(1, usr, i, &all_users, &all_reviews);
										}
									
										exists = true;
									}
								}

								if(!exists){
									cout<< "No User Found!\n";
								}

							}

							//********************************************************************************************************
							//********************************************************************************************************


							//view posts by all users
							//discover new users that you dont follow
							if(select == 6){
								for(int j = all_reviews.size() - 1; j != -1; j--){
									cout << endl <<"Posted By: " << all_reviews[j].get_posted_by() << endl
										<<"Movie: " + all_reviews[j].get_movie() << endl <<
										"Review: " + all_reviews[j].get_body() << endl <<
										"Posted at: " + all_reviews[j].get_time() << endl ;
								}
							}

							//********************************************************************************************************
							//******************************************************************************************************** 

							//show and manage followers
							if(select == 7){
								vector<string> flrs = all_users[i].get_followers();
								vector<string> flng = all_users[i].get_following();
								int opt;
								int ct = 1;

								if(flrs.size() > 0){
									cout << endl;
									for(int j = 0; j!= flrs.size(); j++){
										printf("(%d) - ", ct);
										cout << flrs[j] << endl;
										ct++;
									}

									printf("(%d) - Go Back\n\nChoose Option (1 - %d): ", ct, ct);
									cin >> opt;

									if(opt != ct){
										bool amflng = false;
										string usr = flrs[opt - 1];
										for(int j = 0; j!= flng.size(); j++){
											if(usr == flng[j]){
												amflng = true;
											}
										}

										if(amflng){
											update_following(2, usr, i, &all_users, &all_reviews);
										}
										else{
											update_following(1, usr, i, &all_users, &all_reviews);
										}
									}

								}

								else{
									cout << endl << "You have 0 followers." << endl;
								}
							}

							//********************************************************************************************************
							//********************************************************************************************************
							
							//show and manage users you follow
							if(select == 8){

								vector<string> flng = all_users[i].get_following();
								int opt;
								int ct = 1;

								if(flng.size() > 0){
									cout << endl;
									for(int j = 0; j!= flng.size(); j++){
										printf("(%d) - ", ct);
										cout << flng[j] << endl;
										ct++;
									}

									printf("(%d) - Go Back\n\nChoose Option (1 - %d): ", ct, ct);
									cin >> opt;

									if(opt != ct){
										string usr = flng[opt - 1];
										update_following(2, usr, i, &all_users, &all_reviews);
									}
								}

								else{
									cout << endl << "You are following 0 users." << endl;
								}

								if(opt >= ct){
									continue;
								}
								
							}

							//********************************************************************************************************
							//********************************************************************************************************		
						}
					}
				}
			}

			//Input validation for correct email
			if(found == false){
			cout << endl << "Incorrect Email" << endl;
			}			
		}

		//********************************************************************************************************
		//********************************************************************************************************

		//Sign-Up screen
		else if(select == 1){
			cout << endl;
			string id;
			string pwd;
			

			cout << "Enter Email (must be atleast 5 characters): ";
			cin >> id;

			pwd = change_pwd();
			User nw;
			nw.set_id(id);
			nw.set_pwd(pwd);
			all_users.push_back(nw);
			db.add_user(id, pwd);
			
			cout << endl << "Account Created!" << endl;
		}
	}

	return 0;

}

//function definitions

//********************************************************************************************************
//********************************************************************************************************


//function to follow or unfollow a user
void update_following(int choice, string usr, int i, vector<User> *all_users, vector<Reviews> *all_reviews){
	int opt;
	Data db;
	

	for(unsigned int j = 0; j != (*all_users).size(); j++){
		if(usr == all_users->at(j).get_id()){
			if(choice == 1){
				cout << "\n(1) - Follow \n(2) - View Posts\n(3) - Go Back\n\nChoose Option (1-3): ";
			}
			
			else if(choice == 2){
				cout << "\n(1) - Unfollow \n(2) - View Posts\n(3) - Go Back\n\nChoose Option (1-3): ";
			}
			cin >> opt;

			if(opt == 1){
				if(choice == 1){
					all_users->at(i).add_following(usr);
					all_users->at(j).add_follower(all_users->at(i).get_id());
					db.add_follower(usr, all_users->at(i).get_id());
					db.add_following(all_users->at(i).get_id(), usr);
					cout <<endl<< "Following " << usr  << "!"<< endl;
				}

				else if(choice == 2){
					all_users->at(i).remove_following(usr);
					all_users->at(j).remove_follower(all_users->at(i).get_id());
					//db.update_following(all_users);//functions to unfollow user in data files
					//db.update_followers(all_users);//need changes for correct functionality
					cout <<endl<< "Unfollowed " << usr  << "!"<< endl;
				}
			}

			//Display reviews posted by a specific user
			else if(opt == 2){
				int count = 1;

				for(unsigned int k = 0; k != (*all_reviews).size(); k++){
					if(all_reviews->at(k).get_posted_by() == all_users->at(j).get_id()){
						cout << endl <<  count << ". Movie: " + all_reviews->at(k).get_movie() 
							<< endl << "Review: " + all_reviews->at(k).get_body() << endl <<
							"Posted at: " + all_reviews->at(k).get_time() << endl;	
						count++;
					}
				} 

				if(count == 1){
					cout << endl << "This user has not posted any Reviews!\n\n";
				}

			}

			else if(opt == 3){
				break;
			}

		}
	}
}

//********************************************************************************************************
//********************************************************************************************************


//function to create or update password
string change_pwd(){
	string pwd;
	string confirm_pwd;

	cout << endl << "Enter New Password: ";// create tough pwd
	cin >> pwd;

	cout << "Confirm Password: ";
	cin >> confirm_pwd;

	while(confirm_pwd != pwd){
		cout << "Passwords did not match. Try again! \n\nEnter New Password: ";
		cin >> pwd;
		cout << "Confirm Password: ";
		cin >> confirm_pwd;
	}

	return pwd;
}

//********************************************************************************************************
//********************************************************************************************************

//function that returns current time as a string
string current_time(){
	time_t currentTm = time(0);
	tm* ltm = localtime(&currentTm);

	int day, mon, year, sec, min, hr;

	hr = ltm->tm_hour;
	min = ltm->tm_min;
	sec = ltm->tm_sec;
	day = ltm->tm_mday;
	mon = 1 + ltm->tm_mon;
	year = 1900+ltm->tm_year;

	string time = to_string(hr) + ":" + to_string(min) + ":" + to_string(sec) +
			"	" + to_string(day) + "-" +to_string(mon) + "-" + to_string(year);

	return time;
}