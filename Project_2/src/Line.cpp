#include "Line.h"

Line::Line()
{
  id = 0;
  freq = 0;
  numberOfBus = 0;
  busStopList.empty();
  timesList.empty();
}

Line::Line(string textLine)
{
  vector<string> line_tok;

  line_tok = tokenizer(textLine, " ; ");

  id = stoi(line_tok[0]);

  freq = stoi(line_tok[1]);

  busStopList = tokenizer(line_tok[2], ", ");

  timesList = int_tokenizer(line_tok[3], ", ");

  shiftPerDay = (int)((double)(END_HOUR - START_HOUR) / freq) + 1;

  numberOfBus = (int)((double)totalTime() * 2 / freq + 1);
}

string Line::get_token(string to_token, size_t begin, size_t end)
{
  string tokenized;

  for(size_t i = begin; i < end; i++)
    tokenized.push_back(to_token.at(i));

  return tokenized;
}

vector<string> Line::tokenizer (string to_token, string token)
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

vector<int> Line::int_tokenizer (string to_token, string token)
{
  vector<string> to_convert;
  vector<int> to_return;

  to_convert = tokenizer(to_token, token);

  for(vector<string>::iterator i = to_convert.begin(); i != to_convert.end(); i++)
    to_return.push_back(stoi(*i));

  return to_return;
}

unsigned int Line::getId() const
{
  return id;
}

unsigned int Line::getFreq() const
{
  return freq;
}

unsigned int Line::getNumStops() const
{
  return (unsigned int) busStopList.size();
}

unsigned int Line::getStopIndex(string stop) const
{
  unsigned int i;

  for(i = 0; i < getNumStops(); i++)
    if(busStopList[i].compare(stop) == 0)
      return i;

  return -1;
}

vector<string> Line::getBusStops() const
{
  return busStopList;
}

vector<int> Line::getTimings() const
{
  return timesList;
}

void Line::setID(int ID)
{
  id=ID;
}

void Line::setFreq(int Freq)
{
  freq = Freq;
}

void Line::setStops(vector<string> newStops)
{
  busStopList = newStops;
}

void Line::setTimings(vector<int> newTimings)
{
  timesList = newTimings;
}

void Line::copy(Line lineToCopy)
{
  setID(lineToCopy.getId());

  setFreq(lineToCopy.getFreq());

  setStops(lineToCopy.getBusStops());

  setTimings(lineToCopy.getTimings());
}

void Line::addStop(string newStop)
{
  busStopList.push_back(newStop);
}

void Line::addTime(int newTime)
{
  timesList.push_back(newTime);
}

unsigned int Line::totalTime()
{
  unsigned int sum = 0;

  vector<int>::iterator j;

  for(j = timesList.begin(); j != timesList.end(); j++)
    sum += *j;

  return sum;
}

unsigned int Line::totalTime(size_t stop, int way)
{
  unsigned int sum = 0;
  vector<int>::iterator j;

  switch (way)
  {
    case FOWARD:
      for(j = timesList.begin(); j != timesList.end() - (getNumStops() - 1 - stop); j++)
        sum += *j;
      break;
    case BACKWARD:
      if(stop == timesList.size())
        return 0;
      else
      {
        for(size_t i = timesList.size() - 1; i >= stop; i--)
        {
          sum += timesList[i];
          if(i == stop)
            break;
        }
      }
      break;
  }

  return sum;
}

unsigned int Line::totalTime(size_t begin, size_t end)
{
  return totalTime(end, FOWARD) - totalTime(begin, FOWARD);
}

void Line::info()
{
  int indice = 0;
  vector<string>::iterator i;

  cout << endl << "Linha -> " << id << endl;

  cout << "Frequencia de passagem: " << freq << " minutos.\n";

  cout << "Passa em:\n";

  for(i = busStopList.begin(); i != busStopList.end() ; i++)
  {
    cout << right << setw(2) <<indice + 1 << " - " << *i <<endl;
    indice++;
  }

  cout << "Tempo total da viagem e de " << totalTime() << " minutos\n" << endl << endl;
}

void Line::showLineInfo()
{
  cout << "1 - ID da linha " << id << endl;

  cout << "2 - Frequencia da linha " << freq << endl;

  cout << "3 - Paragens da linha: " << endl;

  for(size_t i = 0; i < busStopList.size(); i++)
  {
    if(i!=0)
      cout << " - ";

    cout << busStopList.at(i);
  }
  cout << endl;

  cout << "4 - Tempo entre linhas: " << endl;

for(size_t k = 0; k < timesList.size(); k++)
  {
    if(k!=0)
      cout << " - ";

    cout << timesList.at(k);
  }

  cout << endl;
}

int Line::getNameLength(int pos)
{
  if(pos == -1)
    return busStopList.at(busStopList.size() - 1).length();
  else
    return busStopList.at(pos).length();
}

unsigned int Line::getNameLength()
{
  vector<string>::iterator i;

  unsigned int maior = 0;

  for(size_t i = 0; i < busStopList.size(); i++)
  {
    if(busStopList.at(i).length() >  maior)
      maior = busStopList.at(i).length();
  }

  return maior;
}

void Line::lightInfo(int primeira, int ultima)
{
  cout << right << setw (7) << setfill(' ') << "ID: " << left << setw(5) <<  id << setw (5) << setfill(' ');
  cout << left << setw(primeira) << setfill(' ') << busStopList.at(0);
  cout << " - ";
  cout << left << setw(ultima) << setfill(' ') << busStopList.at(busStopList.size() - 1) << endl;
}

void Line::showBusStops()
{
  for(size_t i = 0; i < busStopList.size(); i++)
    cout << i+1 << " - " << busStopList.at(i) << endl;
}

void Line::changeBusStops()
{
  int option;

  while(1)
  {
    showBusStops();
    cout << "Que paragem deseja alterar (0 para sair)" << endl;
    cin >> option;
    if(option==0)
        break;

    cin.ignore();

    getline(cin,busStopList.at(option-1));
      //cin >> busStopList.at(option-1);


    system("clear");
  }
  system("clear");
}

void Line::showTimesList()
{
  for(size_t i = 0; i < timesList.size(); i++)
    cout << i + 1 << " - " << timesList.at(i) << endl;
}

void Line::changeTimesList()
{
  int option;
  while(1)
  {
    showTimesList();
    cout << "Que tempo alterar (0 para sair)" << endl;
    cin >> option;
    if(option==0)
      {
        break;
      }

      cin >> timesList.at(option-1);


      system("clear");
  }
  system("clear");
}
