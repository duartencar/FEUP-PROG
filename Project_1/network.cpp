#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <fstream>
#include "text_manipulation.h"
#include "menus.h"
#include "crew.h"
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
    cout << "\t" << a.stops[i] << endl;

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

	while(1)
	{
		cout << "Insira o tempo ate a proxima paragem: ";

		cin >> tim;

		if(stoi(tim) <= 0)
		{
			cout << "Tempo invalido\n";
			return;
		}

		times.push_back(tim);

		cout << "Insira o nome da proxima paragem\n";

		cin.ignore();

  	getline(cin, stop);

		if(stop.empty())
			break;

		stops.push_back(stop);
	}

	to_insert = prepare_line_for_insert(ide, fre, stops, times);

	insert_to_network(to_insert, v_line, (int)v_line.size());
}

string get_line_to_lines_file (line a)
{
	string to_return;

	to_return.append(to_string(a.identifier));

	to_return.append(" ; ");

	to_return.append(to_string(a.freq));

	to_return.append(" ; ");

	for(int i = 0; i < (int)a.stops.size(); i++)
	{
		if(i == (int)a.stops.size() - 1)
			to_return.append(a.stops[i]);
		else
		{
			to_return.append(a.stops[i]);
			to_return.append(", ");
		}
	}

	to_return.append(" ; ");

	for(int i = 0; i < (int)a.times.size(); i++)
	{
		if(i == (int)a.times.size() - 1)
			to_return.append(to_string(a.times[i]));
		else
		{
			to_return.append(to_string(a.times[i]));
			to_return.append(", ");
		}
	}

	return to_return;
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
