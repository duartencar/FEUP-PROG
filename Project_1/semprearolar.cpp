#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include "text_manipulation.h"
#include "menus.h"
#include "crew.h"

using namespace std;

int main(void)
{ /**************VARIABLES DECLARATION***************/

	ifstream lines_file, drivers_file;

	ofstream lines_new, drivers_new;

	string input;

	vector<line> traffic_network;

	vector<driver> drivers_data;

	int answer = 0;

	/**************VARIABLES DECLARATION***************/
	system("clear"); //cls in windows

	lines_file.open("linhas.txt");

	drivers_file.open("condutores.txt");

	if (!lines_file.is_open())
	{
		cout << "File linhas.txt not found !\n";
		return 1;
	}

	if (!drivers_file.is_open())
	{
		cout << "File condutores.txt not found !\n";
		return 1;
	}

	/*Load lines*/
	while (getline(lines_file, input))
		insert_to_network(input, traffic_network, (int)traffic_network.size());

	/*Load drivers*/
	while (getline(drivers_file, input))
		insert_to_drivers_data(input, drivers_data, (int)drivers_data.size());

	lines_file.close();

	drivers_file.close();

	while (answer != 9)
	{
		main_menu();

		cin >> answer;

		switch (answer)
		{
		case 1:
			show_all_lines(traffic_network);
			system("clear"); //cls in windows
			break;
		case 2:
			show_all_drivers(drivers_data);
			system("clear"); //cls in windows
			break;
		case 3:
			manage_drivers(drivers_data);
			system("clear"); //cls in windows
			break;
		case 4:

			break;

		case 9:
			continue;
		}
	}

	system("clear"); //cls in windows

	return 0;
}
