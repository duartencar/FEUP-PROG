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

string get_token(string to_token, size_t begin, size_t end);

vector<string> tokenizer (string to_token, string token);

vector<int> int_tokenizer (string to_token, string token);

int search_for_id(vector<driver> &a, int id); //both

#endif
