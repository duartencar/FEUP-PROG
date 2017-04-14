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
  char output[75];

	sprintf(output,"%-25s\tID:%d\n",a.name.c_str(), a.identifier);

  printf("%s", output);

	sprintf(output,"%-25s\t%d\n","Horas por turno: ", a.hours_p_day);

  printf("%s", output);

	sprintf(output,"%-25s\t%d\n","Horas por semana: " ,a.hours_p_week);

  printf("%s", output);

	sprintf(output,"%-25s\t%d\n\n","Horas de descanso: " , a.rest_hours);

  printf("%s", output);
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

  sprintf(to_return,"%d;%s;%d;%d;%d\n",a.identifier,a.name.c_str(), a.hours_p_day, a.hours_p_week, a.rest_hours);

  string returner(to_return);

  return returner;
}

int search_for_id(vector<driver> &a, int id) //returns the indice of the driver with an ID
{
  for(int i = 0; i < (int)a.size(); i++)
  {
    if(a[i].identifier == id)
      return i;
  }

  return -1;
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

  x = search_for_id(a, x);

  if(x == -1) //in case it hasn t found any driver with the ID inserted by the user
  {
    while(c != 'y' && c != 'Y' && c!= 'n' && c != 'N')
    {
      cout << "Nao foi encontrado nenhum condutor, pretende inserir um? (y/n)\n";

      cin >> c;
    }

    if(c == 'y' || c == 'Y')
      verbose_inserte_to_drivers_data(a);
    else
      return;

    return;
  }

  system("clear");

  driver_info(a[x]);

  cout << "1 - Nome\n2 - Identificador\n3 - Horas que pode trabalhar por dia\n4 - Horas que pode trabalhar por semana\n5 - Horas de descanso\n";

  cout << "O que pretende alterar? <Resp (espaco) nova_informacao\n";

  cin.ignore();

  getline(cin, resposta);

  resp = tokenizer(resposta, " ");

  switch(stoi(resp[0])) //opcao que o utilizador selecionou
  {
    case 1:
      a[x].name.clear();
      for(int i = 1; i < (int)resp.size(); i++)
      {
        a[x].name.append(resp[i]);
        a[x].name.append(" ");
      }
      break;
    case 2:
      if(search_for_id(a, stoi(resp[1])) == -1)
        a[x].identifier = stoi(resp[1]);
      else
        printf("Esse identificador ja existe!\n");
      break;
    case 3:
      a[x].hours_p_day = stoi(resp[1]);
      break;
    case 4:
      a[x].hours_p_week = stoi(resp[1]);
      break;
    case 5:
      a[x].rest_hours = stoi(resp[1]);
      break;
    default:
      printf("Opcao invalida\n");
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
  }

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

  update_drivers_file(v_driver);
}
