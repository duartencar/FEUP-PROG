#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <fstream>
#include "menus.h"

using namespace std;

typedef struct
{
	int identifier;
	int freq;
	vector<string> stops;
	vector<int> times;
} line;

typedef struct
{
	string name;
	vector<int> lines;
} stop;

typedef struct
{
	string name;
	int identifier;
	int hours_p_day;
	int hours_p_week;
	int rest_hours;
} driver;

string get_token(string to_token, size_t begin, size_t end);

vector<string> tokenizer (string to_token, string token);

vector<int> int_tokenizer (string to_token, string token);

void insert_to_network(string read, vector<line> &v_line, int size);

void insert_to_drivers_data(string read, vector<driver> &v_driver, int size);

void verbose_inserte_to_drivers_data(vector<driver> &v_driver);

void line_info (line a);

void driver_info(driver a);

void show_all_lines(vector<line> a);

void show_all_drivers(vector<driver> a);

void main_menu();

string get_line_to_drivers_file(driver a);

int search_for_id(vector<driver> &a, int id);

void edit_drivers_data(vector<driver> &a);

void update_drivers_file (vector<driver> &a);

void manage_drivers(vector<driver> &v_driver);

void manage_drivers_menu();
