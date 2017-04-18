#ifndef _NETWORK_H_
#define _NETWORK_H_

using namespace std;

typedef struct
{
	int identifier;
	int freq;
	vector<string> stops;
	vector<int> times;
} line;

#define START_HOUR 21600 //06:00
#define END_HOUR 74700	//20:45
#define FOWARD 1
#define BACKWARD -1

void insert_to_network(string read, vector<line> &v_line, int size); //inserts the data caontained in 'read' to the network struct

void line_info (line a);  //prints everything realated to the line 'a'

void show_all_lines(vector<line> a); //prints all lines by calling line_info

int search_for_line_id(vector<line> a, int id); //checks if a given id exists in the network, returns vector index if it does, -1 if it doesn t

string prepare_line_for_insert (int identifier, int freq, vector<string> &stops, vector<string> &times); //formats a string to insert to struct

void verbose_insert_to_network(vector<line> &v_line); //interacts with user to gather data, and inserts it by calling prepare_line_for_insert and insert_to_network

string get_line_to_lines_file (line a);  //formats a string to print to file

void edit_network_data(vector<line> &a); //interacts with user to get his decision

void update_lines_file (vector<line> &a); //creates and prints new data to file

void manage_lines(vector<line> &v_line); //interacts with user to get his decision

void print_header (line &a, char *lineToPrint, int stop, int direction); //prints a header with the line stops

int time_until_stop (line &a, int stop, int direction); //calculates the time from the start/end of a line to a given stop and returns it

char* get_hour_format(int tim); //returns string with time in normal hour format

void showTimeTable(vector<line> &a, int stop); //prints the Timetable of a stop

void all_showTimeTable(line &a); //prints the Timetable of a line

void all_TimeTable(vector<line> &a); //interacts with user to get a line and calls all_showTimeTable

void stop_TimeTable(vector<line> &a); //interacts with user to get a line and a stop and calls showTimeTable

void timeTable (vector<line> &v_line); //gets user decisions

#endif
