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
{  /**************VARIABLES DECLARATION***************/

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
		cout << "File linhas.txt nao encontrado !\n";
		return 1;
	}

	if (!drivers_file.is_open())
	{
		cout << "File condutores.txt nao encontrado !\n";
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

	while (answer != 6)
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
		case 6:
			continue;
		default:
			cout << "Opcao invalida!\n";
			break;
		}
	}

	system("clear"); //cls in windows

	return 0;
}

void main_menu()
{
	cout << internal << setw(30) << "Semprarrolar - Transportadora" << endl;

	cout << "1 - Mostrar todas as linhas\n";

	cout << "2 - Mostrar todos os condutores\n";

	cout << "3 - Gerir condutores\n";

	cout << "4 - Gerir linhas\n";

	cout << "5 - Horários\n";

	cout << "6 - Sair\n";
}

void manage_drivers_menu()
{
	system("clear");

	cout << "1 - Editar um motorista existente\n";

	cout << "2 - Inserir um novo motorista\n";

	cout << "3 - Sair\n";
}

void manage_lines_menu()
{
	system("clear");

	cout << "1 - Editar uma linha existente\n";

	cout << "2 - Inserir uma nova linha\n";

	cout << "3 - Sair\n";
}

void edit_driver_menu()
{
	cout << "1 - Nome\n2 - Identificador\n3 - Horas que pode trabalhar por dia\n4 - Horas que pode trabalhar por semana\n5 - Horas de descanso\n";

  cout << "O que pretende alterar? <Resp ('-') nova_informacao\n";
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

	cout << "3 - Sair\n";
}
