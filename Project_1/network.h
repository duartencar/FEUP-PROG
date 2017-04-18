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

void insert_to_network(string read, vector<line> &v_line, int size); //network

void line_info (line a);  //network

void show_all_lines(vector<line> a); //network

int search_for_line_id(vector<line> a, int id);

string prepare_line_for_insert (int identifier, int freq, vector<string> &stops, vector<string> &times);

void verbose_insert_to_network(vector<line> &v_line);

string get_line_to_lines_file (line a);

void edit_network_data(vector<line> &a);

void update_lines_file (vector<line> &a);

void manage_lines(vector<line> &v_line);

void print_header (line &a, char *lineToPrint, int stop, int direction);

int time_until_stop (line &a, int stop, int direction);

char* get_hour_format(int tim);

void showTimeTable(vector<line> &a, int stop);

void all_showTimeTable(line &a);

void all_TimeTable(vector<line> &a);

void stop_TimeTable(vector<line> &a);

void timeTable (vector<line> &v_line);

#endif
