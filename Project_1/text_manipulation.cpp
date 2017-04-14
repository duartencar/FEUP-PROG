#include "text_manipulation.h"
#include "menus.h"
#include "crew.h"

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

int search_for_id(vector<driver> &a, int id) //returns the indice of the driver with an ID
{
  for(int i = 0; i < (int)a.size(); i++)
  {
    if(a[i].identifier == id)
      return i;
  }

  return -1;
}

void manage_lines(vector<line> &v_line)
{

}
