#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <fstream>
#include "semprearolar.h"
#include "text_manipulation.h"
#include "network.h"

using namespace std;

void insert_to_network(string read, vector<line> &v_line, int size)
{
	vector<string> line_tok;

	line_tok = tokenizer(read, ";");

	v_line.push_back(line());

	v_line[size].identifier = stoi(line_tok[0]);

	v_line[size].freq = stoi(line_tok[1]);

	v_line[size].stops = tokenizer(line_tok[2], ",");

	v_line[size].times = int_tokenizer(line_tok[3], ",");
}

void line_info (line a)
{
	int sum = 0;

  cout << endl << "Linha -> " << a.identifier << endl;

  cout << "Frequencia de passagem: " << a.freq << " minutos.\n";

  cout << "Passa em:\n";

  for(int i = 0; i < (int)a.stops.size(); i++)
    printf("\t%-2d - %s\n", i+1, a.stops[i].c_str());

  for(int i = 0; i < (int)a.times.size(); i++)
    sum += a.times[i];

	cout << "Tempo total da viagem e de " << sum << " minutos\n" << endl << endl;
}

void show_all_lines(vector<line> a)
{
	system("clear");

	char c = 'n';

	while (c != 'y' && c != 'Y')
	{
		for (int i = 0; i < (int)a.size(); i++)
			line_info(a[i]);

		cout << "Leave? (y/n)\n";

		cin >> c;
	}
}

int search_for_line_id(vector<line> a, int id)
{
	for(int i = 0; i < (int)a.size(); i++)
	{
		if(a[i].identifier == id)
			return i;
		}

	return -1;
}

string prepare_line_for_insert (int identifier, int freq, vector<string> &stops, vector<string> &times)
{
	char line[750];

	sprintf(line,"%d ; %d ; ", identifier, freq);

	for(int i = 0; i < (int)stops.size(); i++)
	{
		if(i == (int)stops.size() - 1)
			strcat(line, stops[i].c_str());
		else
		{
			strcat(line, stops[i].c_str());
			strcat(line, ", " );
		}
	}

	strcat(line, " ;");

	for(int i = 0; i < (int)times.size(); i++)
	{
		if(i == (int)times.size() - 1)
		{
			strcat(line, " ");
			strcat(line, times[i].c_str());
		}
		else
		{
			strcat(line, " ");
			strcat(line, times[i].c_str());
			strcat(line, ",");
		}
	}

	string to_return(line);

	return to_return;
}

void verbose_insert_to_network(vector<line> &v_line)
{
	int ide;
	int fre;
	string stop, tim;
	vector<string> stops;
	vector<string> times;
	string to_insert;

	cout << "Insira o identificador da linha: ";

	cin >> ide;

	if(search_for_line_id(v_line, ide) > 0)
	{
		cout << "Esse identificador ja existe!\n";
		return;
	}

	cout << "Insira a frequencia de partida da linha: ";

	cin >> fre;

	if(fre <= 0)
	{
		cout << "A frequencia tem de ser maior ou igual a 0\n";
		return;
	}

	cout << "Insira o nome da primeira paragem\n";

	cin.ignore();

	getline(cin, stop);

	stops.push_back(stop);

	cout << "Quando nao quiser inserir mais paragens insira um tempo 0\n";

	while(1)
	{
		cout << "Insira o tempo ate a proxima paragem: ";

		cin >> tim;

		if(stoi(tim) <= 0)
		{
			cout << "Insercao terminada\n";
			break;
		}

		times.push_back(tim);

		cout << "Insira o nome da proxima paragem\n";

		cin.ignore();

  	getline(cin, stop);

		stops.push_back(stop);
	}

	to_insert = prepare_line_for_insert(ide, fre, stops, times);

	insert_to_network(to_insert, v_line, (int)v_line.size());
}

string get_line_to_lines_file (line a)
{
	string to_return;

	to_return.append(to_string(a.identifier));

	to_return.append(";");

	to_return.append(to_string(a.freq));

	to_return.append(";");

	for(int i = 0; i < (int)a.stops.size(); i++)
	{
		if(i == (int)a.stops.size() - 1)
			to_return.append(a.stops[i]);
		else
		{
			to_return.append(a.stops[i]);
			to_return.append(",");
		}
	}

	to_return.append(";");

	for(int i = 0; i < (int)a.times.size(); i++)
	{
		if(i == (int)a.times.size() - 1)
			to_return.append(to_string(a.times[i]));
		else
		{
			to_return.append(to_string(a.times[i]));
			to_return.append(",");
		}
	}

	return to_return;
}

void edit_network_data(vector<line> &a)
{
	int x;

	char c;

	string resposta;

	vector<string> resp;

	vector<int> res;

	printf("Autocarro\t   Origem\t\t         Fim\n\n");
	for(int i = 0; i < (int)a.size(); i++)
		printf("    %d\t\t%-20s-     %-20s\n",a[i].identifier, a[i].stops[0].c_str(), a[i].stops[a[i].stops.size() - 1].c_str());

	cout << endl << endl << "Qual a e a linha que pretende alterar? \n";

	cin >> x;

	x = search_for_line_id(a, x);

	if(x == -1) //in case it hasn t found any driver with the ID inserted by the user
  {
    while(c != 'y' && c != 'Y' && c!= 'n' && c != 'N')
    {
      cout << "Essa linha nao existe, pretende criar uma nova? (y/n)\n";

      cin >> c;
    }

    if(c == 'y' || c == 'Y')
      verbose_insert_to_network(a);
    else
      return;

    return;
  }

	system("clear");

	line_info(a[x]);

	edit_line_menu();

	cin.ignore();

	getline(cin, resposta);

	resp = tokenizer(resposta, "-");

	switch (stoi(resp[0]))
	{
		case 1:
			if(search_for_line_id(a, stoi(resp[1])) == -1)
				a[x].identifier = stoi(resp[1]);
			else
				cout << "Esse identificador ja existe!\n";
			break;
		case 2:
			a[x].freq = stoi(resp[1]);
			break;
		case 3:
			if(((int)resp.size() - 1) < 2)
			{
				cout << "Tem de inserir pelo menos duas paragens\n";
				break;
			}
			a[x].stops.clear();
			for(int i = 1; i < (int)resp.size(); i++)
        a[x].stops.push_back(resp[i]);
			if((int)a[x].stops.size() != (int)(a[x].times.size() - 1))
			{
				res.clear();

				while((int)res.size() != (int)(a[x].stops.size() - 1))
				{
					res.clear();

					printf("Insira %d tempos entre paragens (separados por espacos):",(int)a[x].stops.size() - 1);

					cin.ignore();

					getline(cin, resposta);

					res = int_tokenizer(resposta, " ");
				}
				a[x].times = res;
			}
      break;
		case 4:
			a[x].times.clear();
			if(((int)resp.size() - 1) != ((int)a[x].stops.size() - 1))
			{
				printf("Tem de inserir %d tempos\n", (int)a[x].stops.size() - 1);
				break;
			}
			for(int i = 1; i < (int)resp.size(); i++)
        a[x].times.push_back(stoi(resp[i]));
      break;
		default:
			printf("Opcao invalida\n");
			break;
	}
}

void update_lines_file (vector<line> &a)
{
	ofstream lines_file;

	lines_file.open("linhas.txt", ios::out | ios::trunc);

	if (!lines_file.is_open())
		cout << "File linhas.txt not found !\n";

	for(int i = 0; i < (int)a.size(); i++)
		lines_file << get_line_to_lines_file(a[i]) << endl;

	lines_file.close();
}

void manage_lines(vector<line> &v_line)
{
	int resp = 0;

	while(resp < 1 || resp > 3)
	{
		manage_lines_menu();

		cin >> resp;

		switch(resp)
		{
			case 1:
				edit_network_data(v_line);
				system("clear");
				break;
			case 2:
				verbose_insert_to_network(v_line);
				break;
			case 3:
				break;
		}
	}
	update_lines_file(v_line);
}

void print_header (line &a, char *lineToPrint, int stop, int direction)
{
	memset(lineToPrint, 0, 1000);

	switch(direction)
	{
		case FOWARD:
			for(int i = stop; i < (int)a.stops.size(); i++)
				sprintf(lineToPrint,"%s%-20s\t",lineToPrint,a.stops[i].c_str());
			lineToPrint[999] = '\0';
			printf("%s\n", lineToPrint);
			break;
		case BACKWARD:
			for(int i = stop; i > -1; i--)
				sprintf(lineToPrint,"%s%-20s\t",lineToPrint,a.stops[i].c_str());
			lineToPrint[999] = '\0';
			printf("%s\n", lineToPrint);
			break;
	}

	memset(lineToPrint, 0, 1000);
}

int time_until_stop (line &a, int stop, int direction)
{
	int total = 0;

	switch(direction)
	{
		case FOWARD:
			if(stop == 0)
				return 0;
			for(int i = 0; i < stop; i++)
				total = total + a.times[i - 1] * 60;
			break;
		case BACKWARD:
			if(stop == 0)
				return 0;
			for(int i = stop; i > 0; i--)
				total = total + a.times[i - 1] * 60;
			break;
	}

	return total;
}

char* get_hour_format(int tim)
{
	int hours, min;

	char *hour;

	hour = (char *)malloc(6 * sizeof(char));

	hours = (int)(tim / 3600);

	min = (tim - hours*3600) / 60;

	sprintf(hour,"%02d:%02d", hours % 24, min % 60);

	hour[5] = '\0';

	return hour;
}

void showTimeTable(line &a, int stop)
{
	int firstBus = START_HOUR;
	char resp;
	vector<char*> horas;

	char line[1000];

	while(resp != 'y' && resp != 'Y')
	{
	/*Print first direction*/
		system("clear");

		printf("\t\t\t\tSENTIDO: %s -> %s\n\n",a.stops[stop].c_str(), a.stops[(int)a.stops.size() - 1].c_str());

		print_header(a, line, stop, FOWARD);

		firstBus = firstBus + time_until_stop(a, stop, FOWARD);

		for(int j = firstBus; j <= END_HOUR; j = j + a.freq * 60)
		{
			for(int i = stop; i < (int)a.stops.size(); i++)
				printf("%-20s\t", get_hour_format(j + time_until_stop(a, i + 1, FOWARD)));

			cout << endl;
		}

		cout << endl << endl << endl;

	/*Print second direction*/
		printf("\t\t\t\tSENTIDO: %s -> %s\n\n",a.stops[stop].c_str(), a.stops[0].c_str());

		print_header(a, line, stop, BACKWARD);

		firstBus = START_HOUR + 2 * time_until_stop(a, (int)a.stops.size(), FOWARD);

		for(int j = firstBus; j <= END_HOUR; j = j + a.freq * 60)
		{
			for(int i = stop; i > -1; i--)
				horas.push_back(get_hour_format(j - time_until_stop(a, i + 1 , FOWARD)));

			for(int i = 0; i < (int)horas.size(); i++)
				printf("%-20s\t", horas[i]);

			cout << endl;

			horas.clear();
		}

		cout << endl << endl << "pretende sair? (y/n)\n";

		cin >> resp;
	}
}

void all_showTimeTable(line &a)
{
	int firstBus = START_HOUR;
	char resp;
	vector<char*> horas;

	char line[1000];

	while(resp != 'y' && resp != 'Y')
	{
	/*Print first direction*/
		system("clear");

		printf("\t\t\t\tSENTIDO: %s -> %s\n\n",a.stops[0].c_str(), a.stops[(int)a.stops.size() - 1].c_str());

		print_header(a, line, 0, FOWARD);

		firstBus = firstBus + time_until_stop(a, 0, FOWARD);

		for(int j = firstBus; j <= END_HOUR; j = j + a.freq * 60)
		{
			for(int i = 0; i < (int)a.stops.size(); i++)
				printf("%-20s\t", get_hour_format(j + time_until_stop(a, i + 1, FOWARD)));

			cout << endl;
		}

		cout << endl << endl << endl;

	/*Print second direction*/
		printf("\t\t\t\tSENTIDO: %s -> %s\n\n",a.stops[(int)a.stops.size() - 1].c_str(), a.stops[0].c_str());

		print_header(a, line, (int)a.stops.size() - 1, BACKWARD);

		firstBus = START_HOUR + 2 * time_until_stop(a, (int)a.stops.size(), FOWARD);

		for(int j = firstBus; j <= END_HOUR; j = j + a.freq * 60)
		{
			for(int i = (int)a.stops.size() - 1; i > -1; i--)
				horas.push_back(get_hour_format(j - time_until_stop(a, i + 1 , FOWARD)));

			for(int i = 0; i < (int)horas.size(); i++)
				printf("%-20s\t", horas[i]);

			cout << endl;

			horas.clear();
		}

		cout << endl << endl << "pretende sair? (y/n)\n";

		cin >> resp;
	}
}
void all_TimeTable(vector<line> &a)
{
	int ide = -1;

	system("clear");

	printf("Autocarro\t   Origem\t\t         Fim\n\n");

	for(int i = 0; i < (int)a.size(); i++)
		printf("    %d\t\t%-20s-     %-20s\n",a[i].identifier, a[i].stops[0].c_str(), a[i].stops[a[i].stops.size() - 1].c_str());

	while(ide < 0)
	{
		cout << "Insira o identificador da linha: ";

		cin >> ide;

		ide = search_for_line_id(a, ide);

		if(ide == -1)
			cout << "Essa linha nao existe!\n";
	}

	all_showTimeTable(a[ide]);
}

void stop_TimeTable(vector<line> &a)
{
	int stop = -1, ide = -1;

	system("clear");

	printf("Autocarro\t   Origem\t\t         Fim\n\n");

	for(int i = 0; i < (int)a.size(); i++)
		printf("    %d\t\t%-20s-     %-20s\n",a[i].identifier, a[i].stops[0].c_str(), a[i].stops[a[i].stops.size() - 1].c_str());

	while(ide < 0)
	{
		cout << "Insira o identificador da linha: ";

		cin >> ide;

		ide = search_for_line_id(a, ide);

		if(ide == -1)
			cout << "Essa linha nao existe!\n";
	}

	while(stop < 0 || stop > (int)a[ide].stops.size())
	{
		system("clear");

		line_info(a[ide]);

		cout << "Insira o numero da paragem que pretende: ";;

		cin >> stop;
	}

	showTimeTable(a[ide], stop - 1);
}

void timeTable (vector<line> &v_line)
{
	int resp = 0;

	while(resp < 1 || resp > 3)
	{
		TimeTable_menu();

		cin >> resp;

		switch(resp)
		{
			case 1:
				all_TimeTable(v_line);
				system("clear");
				break;
			case 2:
				stop_TimeTable(v_line);
				system("clear");
				break;
			case 3:
				break;
		}
	}
}
