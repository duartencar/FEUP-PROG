#ifndef _NETWORK_H_
#define _NETWORK_H_

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
#include "text_manipulation.h"

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

void insert_to_network(string read, vector<line> &v_line, int size); //network

void line_info (line a);  //network

void show_all_lines(vector<line> a); //network

int search_for_line_id(vector<line> a, int id);

string prepare_line_for_insert (int identifier, int freq, vector<string> &stops, vector<string> &times);

void verbose_insert_to_network(vector<line> &v_line);

void update_drivers_file (vector<driver> &a);

void manage_lines(vector<line> &v_line);

#endif
