#include "text_manipulation.h"
#include "menus.h"

using namespace std;

string get_token(string to_token, size_t begin, size_t end)
{
  string tokenized;

  for(size_t i = begin; i < end; i++)
    tokenized.push_back(to_token.at(i));

  return tokenized;
}

vector<string> tokenizer (string to_token, string token)
{
	size_t found, last_found = -1;

	vector<string> tokens;

	while ((found = to_token.find(token, last_found + 1)) != to_token.npos)
	{
		tokens.push_back(get_token(to_token, last_found + 1, found));
		last_found = found;
	}

	tokens.push_back(get_token(to_token, last_found + 1, to_token.size()));

	return tokens;
}

vector<int> int_tokenizer (string to_token, string token)
{
  vector<string> to_convert;
  vector<int> to_return;

  to_convert = tokenizer(to_token, token);

  for(int i = 0; i < (int)to_convert.size(); i++)
    to_return.push_back(stoi(to_convert[i]));

  return to_return;
}

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

void driver_info(driver a)
{
	cout << a.name << setw(15) << a.identifier << endl << endl;

	cout << "Horas por turno: " << setw(15) << a.hours_p_day << endl;

	cout << "Horas por semana: " << setw(15) << a.hours_p_week << endl;

	cout << "Horas de descanso: " << setw(13) << a.rest_hours << endl << endl;
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

void show_all_drivers(vector<driver> a)
{
	system("clear");

	char c = 'n';

	while (c != 'y' && c != 'Y')
	{
		for (int i = 0; i < (int)a.size(); i++)
			driver_info(a[i]);

		cout << "Leave? (y/n)\n";

		cin >> c;
	}
}

string get_line_to_drivers_file(driver a)
{
  char to_return[256];

  sprintf(to_return,"%d ; %s ; %d ; %d ; %d\n",a.identifier,a.name.c_str(), a.hours_p_day, a.hours_p_week, a.rest_hours);

  string returner(to_return);

  return returner;
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
  }

  switch(resp)
  {
    case 1:

      break;
    case 2:
      verbose_inserte_to_drivers_data(v_driver);
      break;
    case 3:
      break;
  }

  update_drivers_file(v_driver);
}
