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
#include "crew.h"

bool alteracao;

using namespace std;

int search_for_driver_id(vector<driver> &a, int id)
{
	for(int i = 0; i < (int)a.size(); i++)
	{
		if(a[i].identifier == id)
			return i;
	}

	return -1;
}

void insert_to_drivers_data(string read, vector<driver> &v_driver, int size)
{
	vector<string> line_tok;

	line_tok = tokenizer(read, ";");

	v_driver.push_back(driver());

	v_driver[size].identifier = stoi(line_tok[0]);

	v_driver[size].name = line_tok[1];

	v_driver[size].hours_p_day = stoi(line_tok[2]);

	v_driver[size].hours_p_week = stoi(line_tok[3]);

	v_driver[size].rest_hours = stoi(line_tok[4]);
}

void verbose_inserte_to_drivers_data(vector<driver> &v_driver)
{
  string name;

  char drive [256];

  int ide, day, week, rest;

  cout << "Insert driver name: ";

  cin.ignore();

  getline(cin, name);

  cout << "Insert driver identifier: ";

  cin >> ide;

  cout << "Insert the hours that the driver can work per day: ";

  cin >> day;

  cout << "Insert the hours that the driver can work per week: ";

  cin >> week;

  cout << "Insert the hours that the driver has to rest between tasks: ";

  cin >> rest;

  sprintf(drive, "%d;%s;%d;%d;%d", ide, name.c_str(), day, week, rest);

  string to_insert(drive);

  insert_to_drivers_data(to_insert, v_driver, (int)v_driver.size());
}

void driver_info(driver a)
{
  char output[75];

	sprintf(output,"%-25s\tID:%d\n\n",a.name.c_str(), a.identifier);

  printf("%s", output);

	sprintf(output,"%-25s\t%d\n","Horas por turno: ", a.hours_p_day);

  printf("%s", output);

	sprintf(output,"%-25s\t%d\n","Horas por semana: " ,a.hours_p_week);

  printf("%s", output);

	sprintf(output,"%-25s\t%d\n\n","Horas de descanso: " , a.rest_hours);

  printf("%s", output);
}

void show_all_drivers(vector<driver> a)
{
	system("clear");

	char c = 'n';

	while (c != 's' && c != 'S')
	{
		for (int i = 0; i < (int)a.size(); i++)
			driver_info(a[i]);

		cout << "Leave? (s/n)\n";

		cin >> c;
	}
}

string get_line_to_drivers_file(driver a)
{
  char to_return[256];

  sprintf(to_return,"%d;%s;%d;%d;%d\n",a.identifier,a.name.c_str(), a.hours_p_day, a.hours_p_week, a.rest_hours);

  string returner(to_return);

  return returner;
}

void edit_drivers_data(vector<driver> &a)
{
  int x;

  char c = 'o';

  string resposta;

  vector<string> resp;

  system("clear");

  for(int i = 0; i < (int)a.size(); i++)
    cout << a[i].identifier << " - " << a[i].name << endl;

  cout << "Insira o ID do condutor que pretende alterar: ";

  cin >> x;

  x = search_for_driver_id(a, x);

  if(x == -1) //in case it hasn t found any driver with the ID inserted by the user
  {
    while(c != 's' && c != 'S' && c!= 'n' && c != 'N')
    {
      cout << "Nao foi encontrado nenhum condutor, pretende inserir um? (y/n)\n";

      cin >> c;
    }

    if(c == 's' || c == 'S')
      verbose_inserte_to_drivers_data(a);
    else
      return;

    return;
  }

	system("clear");

	driver_info(a[x]);

  edit_driver_menu();

  cin.ignore();

  getline(cin, resposta);

  resp = tokenizer(resposta, "-");

  switch(stoi(resp[0])) //opcao que o utilizador selecionou
  {
    case 1:
      a[x].name.clear();
      a[x].name.assign(resp[1]);
			alteracao = true;
      break;
    case 2:
      if(search_for_driver_id(a, stoi(resp[1])) == -1)
			{
				a[x].identifier = stoi(resp[1]);
				alteracao = true;
			}
      else
        printf("Esse identificador ja existe!\n");
      break;
    case 3:
      a[x].hours_p_day = stoi(resp[1]);
			alteracao = true;
      break;
    case 4:
      a[x].hours_p_week = stoi(resp[1]);
			alteracao = true;
      break;
    case 5:
      a[x].rest_hours = stoi(resp[1]);
			alteracao = true;
      break;
    default:
      printf("Opcao invalida\n");
			alteracao = false;
      break;
  }
}

void update_drivers_file (vector<driver> &a)
{
  ofstream drivers_file;

  drivers_file.open("condutores.txt", ios::out | ios::trunc);

  if (!drivers_file.is_open())
		cout << "File condutores.txt not found !\n";


  for(int i = 0; i < (int)a.size(); i++)
    drivers_file << get_line_to_drivers_file(a[i]);

  drivers_file.close();
}

void manage_drivers(vector<driver> &v_driver)
{
  int resp = 0;

  while(resp < 1 || resp > 3)
  {
    manage_drivers_menu();

    cin >> resp;

    switch(resp)
    {
      case 1:
        edit_drivers_data(v_driver);
        break;
      case 2:
        verbose_inserte_to_drivers_data(v_driver);
        break;
      case 3:
        break;
    }
  }
	if(alteracao)
	{
		update_drivers_file(v_driver);
		cout << "Ficheiro atualizado!\n";
		alteracao = false;
	}
}
