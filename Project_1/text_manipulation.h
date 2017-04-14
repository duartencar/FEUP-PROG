#ifndef _TEXT_MANIPULATION_H_
#define _TEXT_MANIPULATION_H_

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
#include "crew.h"

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

string get_token(string to_token, size_t begin, size_t end);

vector<string> tokenizer (string to_token, string token);

vector<int> int_tokenizer (string to_token, string token);

void insert_to_network(string read, vector<line> &v_line, int size); //network

void line_info (line a);  //network

void show_all_lines(vector<line> a); //network

int search_for_id(vector<driver> &a, int id); //both

void manage_lines(vector<line> &v_line);

#endif
