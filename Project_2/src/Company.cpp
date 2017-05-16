#include "Company.h"

Company::Company() //default constructor
{
  nome = "Default";
  condutores.empty();
  linhas.empty();
}

Company::Company(string name, string fichCondutores, string fichLinhas)
{
  nome = name;
  setLineVector(fichLinhas);
  setDriverVector(fichCondutores);
}

string Company::getNome() const
{
  return nome;
}

void Company::setNome(string myName)
{
  nome = myName;
}

void Company::setLineVector(string myFile)
{
  ifstream f;
  string textLine;

  f.open("../resources/" + myFile);

  if(!f.is_open())
  {
    cerr << "ERRO: Nao foi possivel abrir o ficheiro de linhas!\n";
    exit(1);
  }

  while(getline(f, textLine))
    linhas.push_back(Line(textLine));

  f.close();
}

void Company::setDriverVector(string myFile)
{
  ifstream f;
  string textLine;

  f.open("../resources/" + myFile);

  if(!f.is_open())
  {
    cerr << "ERRO: Nao foi possivel abrir o ficheiro de condutores!\n";
    exit(1);
  }

  while(getline(f, textLine))
    condutores.push_back(Driver(textLine));

  f.close();
}

vector<Line> Company::getLines() const
{
  return linhas;
}

vector<int> Company::getLinesWithStop(string stop) const
{
  vector<int> identificadores;

  vector<Line> lines = getLines();

  vector<string> stops;

  for(vector<Line>::iterator i = lines.begin(); i != lines.end(); i++)
  {
    stops = i->getBusStops();

    for(vector<string>::iterator j = stops.begin(); j != stops.end(); j++)
      if(stop.compare(*j) == 0)
        identificadores.push_back((int)i->getId());
  }

  return identificadores;
}

void Company::showLines()
{
  for(size_t i = 0; i < linhas.size(); i++)
    linhas[i].info();

  cout << endl;
}

void Company::showLines(int i)
{
  system("clear");

  linhas[i].info();

  cout << endl;
}

void Company::showDrivers()
{
  for(size_t i = 0; i < condutores.size(); i++)
    condutores.at(i).info();

  cout << endl;
}

void Company::showDrivers(int i)
{
  condutores[i].info();

  cout << endl;
}

void Company::lightShowDrivers()
{
  for(size_t i = 0; i < condutores.size(); i++)
    condutores.at(i).lightInfo();

  cout << endl;
}

void Company::lightShowDrivers(int i)
{
  condutores.at(i).lightInfo();

  cout << endl;
}

int Company::getMaxNameLenght(size_t pos)
{
  int maior = 0;

  for(size_t i = 0; i < linhas.size(); i++)
    if(linhas.at(i).getNameLength(pos) > maior)
      maior = linhas.at(i).getNameLength(pos);

  return maior;
}

void Company::lightShowLines()
{
  cout << endl;

  for(size_t i = 0; i < linhas.size(); i++)
    linhas.at(i).lightInfo(getMaxNameLenght(0), getMaxNameLenght(- 1));

  cout << endl;
}

void Company::lightShowLines(int i)
{
  linhas.at(i).lightInfo(getMaxNameLenght(0), getMaxNameLenght(-1));

  cout << endl;
}

void Company::addDriver (string toInsert)
{
  condutores.push_back(Driver(toInsert));
}

int Company::CheckDriverId (unsigned int x)
{
  for(int i = 0; i < (int)condutores.size(); i++)
    if(condutores.at(i).getId() == x)
      return i;

  return -1;
}

void Company::deleteDriver (size_t index)
{
  condutores.erase(condutores.begin() + index);
}

void Company::changeDriversettings (int DriverIndex, string newValue, int option)
{
  switch(option)
  {
    case NOME:
      condutores[DriverIndex].setName(newValue);
      break;
    case ID:
      condutores[DriverIndex].setId(stoi(newValue));
      break;
    case MAX_DAY_LOAD:
      condutores[DriverIndex].setMaxHours(stoi(newValue));
      break;
    case MAX_WEEK_LOAD:
      condutores[DriverIndex].setMaxWeekWorkingTime(stoi(newValue));
      break;
    case REST_TIME_NEEDED:
      condutores[DriverIndex].setMinRestTime(stoi(newValue));
      break;
    default:
      return;
  }
}

void Company::changeLines()
{
  int lineToChange, option, newID, newFreq;

  system("clear");

  cout << "Linhas: " << endl;

  for(size_t i=1;i<=linhas.size();i++)
    cout << i << " - " << linhas.at(i-1).getId() << endl;

  cout << "Que linha deseja alterar?" << endl;
  cin >> lineToChange;

  system("clear");

  while(1)
  {
      linhas.at(lineToChange-1).showLineInfo();
      cout << "O que deseja alterar? (5 - Sair)" << endl;
      cout << endl;
      cin >> option;
      system("clear");
    if(option==1)
    {
      cout << "Insira um novo ID" << endl;
      cin >> newID;
      linhas.at(lineToChange-1).setID(newID);
    }
    else if(option==2)
    {
      cout << "Insira uma nova Frequencia" << endl;
      cin >> newFreq;
      linhas.at(lineToChange-1).setID(newFreq);
    }
    else if(option==3)
    {
      linhas.at(lineToChange-1).changeBusStops();
    }
    else if(option==4)
    {
      linhas.at(lineToChange-1).changeTimesList();
    }
    else if(option==5)
    {
      break;
    }
  }
}

int Company::searchLine(int myID)
{
  for(int i = 0; i < (int)linhas.size(); i++)
    if((unsigned int)myID == linhas[i].getId()) /*CORRIGIR chamada da funcao para unsignedint*/
      return i;

  return -1;
}

void Company::insertLine(Line newLine)
{
  linhas.push_back(newLine);
}

void Company::removeLine(int i)
{
  linhas.erase(linhas.begin() + (size_t)i);
}

void Company::printLineToFile()
{
  int k;
  ofstream file;
  cin.clear();
  cin.ignore(10000,'\n');
  string myString;

  cout << "Escolha o nome do ficheiro(.txt): ";

  while(1)
  {
  getline(cin,myString);

  file.open("../resources/" + myString);

  if(file.is_open())
    break;
  else
    cout << "Introduza novamente o nome do ficheiro: ";
  }

  for(int i = 0; i < (int)linhas.size();i++)
  {
    file << linhas.at(i).getId();
    file << " ; ";
    file << linhas.at(i).getFreq();
    file << " ; ";

    for (k = 0; k < (int)linhas.at(i).getBusStops().size();k++)
    {
      file << linhas.at(i).getBusStops().at(k);

      if (k == (int)linhas.at(i).getBusStops().size()-1)
        file << " ; ";
      else
        file << ", ";
    }

    for (k=0; k < (int) linhas.at(i).getTimings().size();k++)
    {
      file << linhas.at(i).getTimings().at(k);

      if (k != (int)linhas.at(i).getTimings().size()-1)
        file << ", ";
    }

    file << endl;
  }

  file.close();
}

void Company::printDiverToFile()
{
  ofstream file;
  cin.clear();
  cin.ignore(1000,'\n');
  string myString;

  cout << "Escolha o nome do ficheiro(.txt): ";

  while(1)
  {
  getline(cin, myString);

  file.open("../resources/" + myString);

  if(file.is_open())
    break;
  else
    cout << "Introduza novamente o nome do ficheiro: ";
  }

  for (int i=0; i < (int)condutores.size(); i++)
  {
    file << condutores.at(i).getId();
    file << " ; ";
    file << condutores.at(i).getName();
    file << " ; ";
    file << condutores.at(i).getShiftMaxDuration();
    file << " ; ";
    file << condutores.at(i).getMaxWeekWorkingTime();
    file << " ; ";
    file << condutores.at(i).getMinRestTime();
    file << endl;
  }

  file.close();
}

string Company::convertToHours(unsigned int to_convert)
{
  char converted[6];

  int hours = to_convert / 60;

  int min = to_convert % 60;

  sprintf(converted, "%02d:%02d", hours, min);

  string to_return(converted);

  return to_return;
}

void Company::printStopsHeader(vector<string> stops, int width, int way)
{
  switch(way)
  {
    case FOWARD:
      cout << "|";
      for(size_t i = 0; i < stops.size(); i++)
      {
        cout << left << setw((width - stops[i].length()) / 2) << " " << setfill(' ');

        cout << left << setw(width) << stops[i];

        cout << left << setw((width - stops[i].length()) / 2) << " " << setfill(' ');
      }
      cout << "|" << endl;
      break;
    case BACKWARD:
      cout << "|";

      for(size_t i = stops.size() - 1; i >= 0; i--)
      {
        cout << left << setw((width - stops.at(i).length()) / 2) << " " << setfill(' ');

        cout << left << setw(width) << stops.at(i);

        cout << left << setw((width - stops.at(i).length()) / 2) << " " << setfill(' ');

        if(i == 0)
          break;
      }
      cout << "|" << endl;
      break;
  }
}

void Company::printStopsHeader(vector<string> stops, int width, int way, int startingStop)
{
  switch(way)
  {
    case FOWARD:
      cout << "|";
      for(size_t i = (size_t)startingStop; i < stops.size(); i++)
      {
        cout << left << setw((width - stops[i].length()) / 2) << " " << setfill(' ');

        cout << left << setw(width) << stops[i];

        cout << left << setw((width - stops[i].length()) / 2) << " " << setfill(' ');
      }
      cout << "|" << endl;
      break;
    case BACKWARD:
      cout << "|";
      for(size_t i = (size_t)startingStop; i >= 0; i--)
      {
        cout << left << setw((width - stops.at(i).length()) / 2) << " " << setfill(' ');

        cout << left << setw(width) << stops.at(i);

        cout << left << setw((width - stops.at(i).length()) / 2) << " " << setfill(' ');

        if(i == 0)
          break;
      }
      cout << "|" << endl;
      break;
  }
}

unsigned int Company::getNumBusStops () const
{
  unsigned int numStops = 0;

  for(size_t i = 0; i != linhas.size(); i++)
    numStops += linhas[i].getNumStops();

  return numStops;
}

void Company::seeAllStops()
{
  vector<Line>::iterator i;
  vector<string> linestops;
  vector<string>::iterator j;
  int numStops = 1;

  for(i = linhas.begin(); i != linhas.end(); i++)
  {
    linestops = i->getBusStops();

    for(j = linestops.begin(); j != linestops.end(); j++)
    {
      cout << right << setw(2) << numStops << " - " << *j << endl;

      numStops++;
    }
  }
}

void Company::seeStopSchedule(unsigned int selectedStop)
{
  unsigned int k = 1;
  vector<Line>::iterator i;
  vector<string> linestops;
  vector<string>::iterator j;
  string resp;
  int width;
  int totalWidth = 0;

  for(i = linhas.begin(); i != linhas.end(); i++)
  {
    linestops = i->getBusStops();

    for(j = linestops.begin(); j != linestops.end(); j++)
    {
      k++;

      if(k == selectedStop)
          break;
    }

    if(k == selectedStop)
        break;
  }

  if(i->getStopIndex(*j) == 0 || i->getStopIndex(*j) == (i->getNumStops() - 1))
  {
    seeSchedule(searchLine(i->getId()));

    return;
  }

  cout << "Linha: " << i->getId() << " Paragem: " << *j << endl << endl;

  width = i->getNameLength();

  for(unsigned int k = i->getStopIndex(*j); k < i->getNumStops(); k++)
    totalWidth += 2 * width - i->getBusStops()[k].length();

  totalWidth -= 14 + 10 + i->getBusStops()[k].length() + i->getBusStops().at(i->getBusStops().size() - 1).length() - 6;

  system("clear");

  cout << right << setw(totalWidth / 2)  << setfill(' ') << " Sentido: " << i->getBusStops().at(i->getStopIndex(*j)) << " -> " << i->getBusStops().at(i->getBusStops().size() - 1);

  totalWidth += 14 + 10 + i->getBusStops()[k].length() + i->getBusStops().at(i->getBusStops().size() - 1).length() - 6;

  cout << endl << "|" << right << setw(totalWidth + 3) << setfill(' ') << "|" << endl;

  printStopsHeader(i->getBusStops(), width, FOWARD, i->getStopIndex(*j));

  for(unsigned int m = START_HOUR; m <= END_HOUR; m += i->getFreq())
  {
    cout << endl << "|";

    for(unsigned int l = i->getStopIndex(*j); l < i->getNumStops(); l++)
    {
      cout << left << setw((width - i->getBusStops()[l].size()) / 2) << " " << setfill(' ');

      cout << left << setw(width) << convertToHours(m + i->totalTime((size_t)l, FOWARD));

      cout << left << setw((width - i->getBusStops()[l].size()) / 2) << " " << setfill(' ');
    }

    cout << "|" << endl;
  }

  cout << endl << "-" << left << setw(totalWidth + 3) << setfill('-') << "-" << endl;

  for(unsigned int k = i->getStopIndex(*j), totalWidth = 0; k > 0; k--)
    totalWidth += 2 * width - i->getBusStops()[k].length();

  totalWidth -= 14 + 10 + i->getBusStops()[i->getStopIndex(*j)].length() + i->getBusStops().at(0).length() - 6;

  cout << right << setw(totalWidth / 2)  << setfill(' ') << " Sentido: " << i->getBusStops().at(i->getStopIndex(*j)) << " -> " << i->getBusStops().at(0);

  totalWidth += 14 + 10 + i->getBusStops()[i->getStopIndex(*j)].length() + i->getBusStops().at(0).length() - 6;

  cout << endl << "|" << right << setw(totalWidth + 3) << setfill(' ') << "|" << endl;

  printStopsHeader(i->getBusStops(), width, BACKWARD, i->getStopIndex(*j));

  for(unsigned int m = START_HOUR + i->totalTime(); m <= END_HOUR; m += i->getFreq())
  {
    cout << endl << "|";

    for(unsigned int l = i->getStopIndex(*j) ;l >= 0 ;l--)
    {
      cout << left << setw((width - i->getBusStops()[l].size()) / 2) << " " << setfill(' ');

      cout << left << setw(width) << convertToHours(m + i->totalTime((size_t)l, BACKWARD));

      cout << left << setw((width - i->getBusStops()[l].size()) / 2) << " " << setfill(' ');

      if( l == 0)
        break;
    }

    cout << "|" << endl;
  }

  cout << endl << "-" << left << setw(totalWidth + 3) << setfill('-') << "-" << endl;

  cout << endl << endl << "Insira -1 para sair\n";

  cin >> resp;

  if(resp.compare("-1") == 0)
    return;
  else
    seeStopSchedule(selectedStop);
}

void Company::seeSchedule(int LineIndex)
{
  Line a(linhas[LineIndex]);

  string resp;

  vector<string> stops = a.getBusStops();

  int width = a.getNameLength();

  int totalWidth = 0;

  for(unsigned int j = 0; j < a.getNumStops(); j++)
    totalWidth += 2 * width - stops[j].length();

  totalWidth -= 14 + 10 + stops.at(0).length() + stops.at(stops.size() - 1).length() - 6;

  system("clear");

  cout << right << setw(totalWidth/2)  << setfill(' ') << "Horario da linha ";

  cout << left << a.getId() << " Sentido: " << stops.at(0) << " -> " << stops.at(stops.size() - 1);

  totalWidth += 14 + 10 + stops.at(0).length() + stops.at(stops.size() - 1).length() - 6;

  cout << endl << "|" << right << setw(totalWidth + 3) << setfill(' ') << "|" << endl;


  printStopsHeader(stops, width, FOWARD);

  for(unsigned int i = START_HOUR; i <= END_HOUR; i += a.getFreq())
  {
    cout << endl << "|";

    for(unsigned int j = 0; j < a.getNumStops(); j++)
    {
      cout << left << setw((width - stops[j].size()) / 2) << " " << setfill(' ');

      cout << left << setw(width) << convertToHours(i + a.totalTime((size_t)j, FOWARD));

      cout << left << setw((width - stops[j].size()) / 2) << " " << setfill(' ');
    }

    cout << "|" << endl;
  }
  cout << endl << "-" << left << setw(totalWidth + 3) << setfill('-') << "-" << endl;

  totalWidth -= 14 + 10 + stops.at(0).length() + stops.at(stops.size() - 1).length() - 6;

  cout << right << setw(totalWidth/2)  << setfill(' ') << "Horario da linha ";

  cout << left << a.getId() << " Sentido: " << stops.at(stops.size() - 1) << " -> " << stops.at(0);

  totalWidth += 14 + 10 + stops.at(0).length() + stops.at(stops.size() - 1).length() - 6;

  cout << endl << "|" << right << setw(totalWidth + 3) << setfill(' ') << "|" << endl << endl;

  printStopsHeader(stops, width, BACKWARD);

  for(unsigned int i = START_HOUR + a.totalTime(); i <= END_HOUR + a.totalTime(); i += a.getFreq())
  {
    cout << endl << "|";

    for(unsigned int j = a.getNumStops() - 1; j >= 0; j--)
    {
      cout << left << setw((width - stops[j].size()) / 2) << " " << setfill(' ');

      cout << left << setw(width) << convertToHours(i + a.totalTime((size_t)j, BACKWARD));

      cout << left << setw((width - stops[j].size()) / 2) << " " << setfill(' ');

      if(j == 0)
        break;
    }

    cout << "|" << endl;
  }

  cout << endl << "-" << left << setw(totalWidth + 3) << setfill('-') << "-" << endl;

  cout << endl << endl << "Insira -1 para sair\n";

  cin >> resp;

  if(resp.compare("-1") == 0)
    return;
  else
    seeSchedule(LineIndex);
}

int Company::getLineIndexOfStop(int stopIndex)
{
  vector<Line> lin = getLines();
  vector<string> stops;

  for(int i = 0, index = 1; i < (int)lin.size(); i++)
  {
    stops = lin[i].getBusStops();

    for(vector<string>::iterator j = stops.begin(); j != stops.end(); j++)
    {
      if(index == stopIndex)
        return i;

      index++;
    }
  }

  return -1;
}

void Company::switchLines(size_t firstIndex, size_t secondIndex)
{
  Line aux(linhas.at(firstIndex));

  linhas.at(firstIndex).copy(linhas.at(secondIndex));

  linhas.at(secondIndex).copy(aux);
}

void Company::calculateTrip(int first, string origin, int second, string destination)
{
  string resp;

  switchLines(0, first);

  switchLines(linhas.size() -1 , second);

  cin >> resp;
}
