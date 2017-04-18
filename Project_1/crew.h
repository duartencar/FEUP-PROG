#ifndef _CREW_H_
#define _CREW_H_

using namespace std;

typedef struct
{
	string name;
	int identifier;
	int hours_p_day;
	int hours_p_week;
	int rest_hours;
} driver;

int search_for_driver_id(vector<driver> &a, int id); //checks if an id exists, returns vector index if it does, -1 if it doesnt

void insert_to_drivers_data(string read, vector<driver> &v_driver, int size); //inserts data into de v_driver struct

void verbose_inserte_to_drivers_data(vector<driver> &v_driver); //asks the user for data and calls insert_to_drivers_data

void driver_info(driver a); //prints driver 'a' information

void show_all_drivers(vector<driver> a); //prints all dirvers information (calls driver_info)

string get_line_to_drivers_file(driver a); //formats a line to be printed to de drivers file

void edit_drivers_data(vector<driver> &a); //interacts with user to edit a driver data

void update_drivers_file (vector<driver> &a); //creates new file and calls get_line_to_drivers_file to print

void manage_drivers(vector<driver> &v_driver); //receives the user decision

#endif
