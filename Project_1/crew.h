#ifndef _CREW_H_
#define _CREW_H_

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
	string name;
	int identifier;
	int hours_p_day;
	int hours_p_week;
	int rest_hours;
} driver;

void insert_to_drivers_data(string read, vector<driver> &v_driver, int size); //crew

void verbose_inserte_to_drivers_data(vector<driver> &v_driver); //crew

void driver_info(driver a); //crew

void show_all_drivers(vector<driver> a); //crew

string get_line_to_drivers_file(driver a); //crew

void edit_drivers_data(vector<driver> &a); //crew

void update_drivers_file (vector<driver> &a); //crew

void manage_drivers(vector<driver> &v_driver); //crew

#endif