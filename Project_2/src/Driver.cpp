#include "Driver.h"

Driver::Driver()
{
  id = -1;
  name = "UnNamed";
  maxHours = -1;
  maxWeekWorkingTime = -1;
  minRestTime = -1;
  shifts.empty();
}

Driver::Driver(string textLine)
{
  vector<string> line_tok;

  line_tok = tokenizer(textLine, " ; ");

  id = stoi(line_tok[0]);

  name = line_tok[1];

  maxHours = stoi(line_tok[2]);

  maxWeekWorkingTime = stoi(line_tok[3]);

  minRestTime = stoi(line_tok[4]);

  shifts.clear();
}

string Driver::get_token(string to_token, size_t begin, size_t end)
{
  string tokenized;

  for(size_t i = begin; i < end; i++)
    tokenized.push_back(to_token.at(i));

  return tokenized;
}

vector<string> Driver::tokenizer (string to_token, string token)
{
  size_t found, last_found = -1;

	vector<string> tokens;

	while ((found = to_token.find(token, last_found + 1)) != to_token.npos)
	{
		tokens.push_back(get_token(to_token, last_found + 1, found));

    last_found = found + token.length() - 1;
	}

	tokens.push_back(get_token(to_token, last_found + 1, to_token.size()));

  return tokens;
}

vector<int> Driver::int_tokenizer (string to_token, string token)
{
  vector<string> to_convert;

  vector<int> to_return;

  to_convert = tokenizer(to_token, token);

  for(vector<string>::iterator i = to_convert.begin(); i != to_convert.end(); i++)
    to_return.push_back(stoi(*i));

  return to_return;
}

unsigned int Driver::getId() const
{
  return id;
}

string Driver::getName() const
{
  return name;
}

unsigned int Driver::getShiftMaxDuration() const
{
  return maxHours;
}

unsigned int Driver::getMaxWeekWorkingTime() const
{
  return maxWeekWorkingTime;
}

unsigned int Driver::getMinRestTime() const
{
  return minRestTime;
}

vector<Shift> Driver::getShifts() const
{
  return shifts;
}

void Driver::setId(unsigned int newID)
{
  id = newID;
}

void Driver::setName(string newName)
{
  name = newName;
}

void Driver::setMaxHours(unsigned int newMaxHours)
{
  maxHours = newMaxHours;
}

void Driver::setMaxWeekWorkingTime(unsigned int newMaxWeekWorkingTime)
{
  maxWeekWorkingTime = newMaxWeekWorkingTime;
}

void Driver::setMinRestTime(unsigned int newMinRestTime)
{
  minRestTime = newMinRestTime;
}

void Driver::info()
{
  cout << "Condutor #" << id << endl;

  cout << "Nome: " << name << endl;

  cout << "Duracao maxima de um turno: " << maxHours << endl;

  cout << "Numero maximo de horas que pode trabalharpor semana: " << maxWeekWorkingTime << endl;

  cout << "Tempo de descanso: " << minRestTime << endl << endl;

  //FALTA -> imprimir turnos!!!
}

void Driver::lightInfo()
{
  cout << right << setw (7) << setfill(' ') << "ID: " << left << setw(5) <<  id << setw (5) << setfill(' ') << name << endl;
}
