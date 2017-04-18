#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include "text_manipulation.h"
#include "crew.h"
#include "network.h"

using namespace std;

void main_menu();
void manage_drivers_menu();
void manage_lines_menu();
void edit_driver_menu();
void edit_line_menu();
void TimeTable_menu();

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

	while (answer != 8)
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
			manage_lines(traffic_network);
			system("clear");
			break;
		case 5:
			timeTable(traffic_network);
			system("clear");
			break;

		case 8:
			continue;
		}
	}

	system("clear"); //cls in windows

	return 0;
}

void main_menu()
{
	cout << internal << setw(30) << "Semprarrolar - Transportadora" << endl;

	cout << "1 - Show all lines\n";

	cout << "2 - Show all drivers\n";

	cout << "3 - Manage drivers\n";

	cout << "4 - Manage lines\n";

	cout << "5 - Horários\n";

	cout << "6 - Plan trip\n";

	cout << "7 - Show necessary drivers for a line workload\n";

	cout << "8 - Leave\n";
}

void manage_drivers_menu()
{
	system("clear");

	cout << "1 - Edit an existing driver\n";

	cout << "2 - Create new driver\n";

	cout << "3 - Leave\n";
}

void manage_lines_menu()
{
	system("clear");

	cout << "1 - Edit an existing line\n";

	cout << "2 - Create new line\n";

	cout << "3 - Leave\n";
}

void edit_driver_menu()
{
	cout << "1 - Nome\n2 - Identificador\n3 - Horas que pode trabalhar por dia\n4 - Horas que pode trabalhar por semana\n5 - Horas de descanso\n";

  cout << "O que pretende alterar? <Resp (espaco) nova_informacao\n";
}

void edit_line_menu()
{
	cout << "1 - Identificador\n";
	cout << "2 - Frequencia de partida\n";
	cout << "3 - Paragens\n";
	cout << "4 - Tempos entre paragens\n";

	cout << "O que pretende alterar? <Resp ('-') nova_informacao, separada por '-' caso seja necessario\n";
}

void TimeTable_menu()
{
	system("clear");

	cout << "1 - Ver horário duma linha inteira\n";

	cout << "2 - Ver horário duma paragem\n";

	cout << "3 - Leave\n";
}
