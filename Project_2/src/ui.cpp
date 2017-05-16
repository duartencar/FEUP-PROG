#include "ui.hpp"

bool edited;

vector<string> getFilesName()
{
  vector<string> v;

  string resp;

  cout << "Insira o nome do ficheiro de condutores: ";

  cin >> resp; v.push_back(resp);

  cout << "Insira o nome do ficheiro de linhas: ";

  cin >> resp; v.push_back(resp);

  return v;
}

void PrintOptions (Company &Enterprise, int menu, int option)
{
  system("clear");
  int width;

  switch(menu)
  {
    case MAIN_M:
      cout <<"--------" << Enterprise.getNome() << "--------" << endl;
      cout << "1 - Gerir condutores\n";
      cout << "2 - Gerir linhas\n";
      cout << "3 - Paragens\n";
      cout << "4 - Planear viagem\n";
      cout << "5 - Sair\n";
      break;
    case MANAGE_DRIVERS_M:
      cout << "----" << Enterprise.getNome() << " ** Gestao de condutores" <<"----" << endl << endl;
      Enterprise.lightShowDrivers();
      cout << "1 - Adicionar condutor\n";
      cout << "2 - Eliminar condutor\n";
      cout << "3 - Editar informacoes dum condutor\n";
      cout << "4 - Voltar\n";
      break;
    case EDIT_DRIVER_M:
      cout << "----" << Enterprise.getNome() << " ** Editar condutor" <<"----" << endl << endl;
      Enterprise.showDrivers(option);
      cout << "1 - Mudar identificador\n";
      cout << "2 - Mudar nome\n";
      cout << "3 - Mudar horas máximas de trabalho diarias\n";
      cout << "4 - Mudar horas máximas de trabalho semanais\n";
      cout << "5 - Mudar horas minimas de descanso entre turnos\n";
      cout << "6 - Voltar\n\n";
      cout << "Insira opcao: ";
      break;
    case MANAGE_LINES_M:
      width = Enterprise.getMaxNameLenght(0) + Enterprise.getMaxNameLenght(-1) + 24 - 20 - Enterprise.getNome().length();
      cout << setw(width / 2) << setfill('-') << Enterprise.getNome() << " ** Gestao de linhas" << setw(width/2) << "-" << setfill('-') << endl << endl;
      Enterprise.lightShowLines();
      cout << "1 - Adicionar linha\n";
      cout << "2 - Eliminar linha\n";
      cout << "3 - Editar uma linha\n";
      cout << "4 - Voltar\n\n";
      break;
    case TIMETABLE_M:
      cout << "----" << Enterprise.getNome() << " ** Visualizacao de horarios" <<"----" << endl << endl;
      Enterprise.lightShowLines();
      cout << "1 - Ver horarios duma linha inteira\n";
      cout << "2 - Ver horarios numa paragem\n";
      cout << "3 - Voltar\n";
      break;
    case STOP_TIMETABLE_M:
      cout << "----" << Enterprise.getNome() << " ** Visualizacao de todas as paragens" << "----" << endl << endl;
      cout << "Insira - 1 para sair a qualquer momento" << endl << endl;
      break;
    case PLAN_TRIP_M:
      cout << "----" << Enterprise.getNome() << " ** Planeamento de viagens" << "----" << endl << endl;
      cout << "1 - Ver linhas que contém uma paragem\n";
      cout << "2 - Calcula e visualizar percurso entre duas paragens\n";
      cout << "3 - Voltar" << endl << endl;
      cout << "Insira uma opcao: ";
      break;
  }
}

bool validAnswer(string answer, int type)
{
  switch(type)
  {
    case INTEIRO:
      try
      {
        stoi(answer);
      }
      catch (const std::invalid_argument& ia)
      {
        return false;
      }
      catch(std::out_of_range& ia)
      {
        return false;
      }
      break;
    case DECIMAL:
      try
      {
        stof(answer);
      }
      catch (const std::invalid_argument& ia)
      {
        return false;
      }
      catch (const std::out_of_range& ia)
      {
        return false;
      }
      break;
  }

  return true;
}

bool addDriver (Company &Enterprise)
{
  string resp;

  string toInsert;

  system("clear");

  cout << "Insira -1 a qualquer momento para parar inserção\n\n";

  /*GET ID*/

  while(1)
  {
    cout << "Insira o ID: ";

    cin.ignore();

    cin >> resp;

    if(resp.compare("-1") == 0)
      return false; //user wants to leave

    if(validAnswer(resp, INTEIRO))
    {
      if(Enterprise.CheckDriverId(stoi(resp)) < 0) //caso o ID nao exista permite a saida
        break;
      else
        cout << "Esse ID ja existe\n";
    }
    else
      cout << endl << "Insira um inteiro!\n";
  }

  toInsert.append(resp);

  toInsert.append(" ; ");

  /*GET ID*/

  /*GET NAME*/

  cout << "Nome: ";

  cin.ignore();

  getline(cin, resp);

  if(resp.compare("-1") == 0)
    return false; //user wants to leave

  toInsert.append(resp);

  toInsert.append(" ; ");

  /*GET NAME*/


  /*GET SHIFT MAX DURATION*/
  while(1)
  {
    cout << "Maxima duracao de um turno: ";

    cin >> resp;

    if(resp.compare("-1") == 0)
      return false; //user wants to leave

    if(validAnswer(resp, INTEIRO))
      break;
  }

  toInsert.append(resp);

  toInsert.append(" ; ");

  /*GET SHIFT MAX DURATION*/

  /*GET WEEK MAX WORKLOAD*/

  while(1)
  {
    cout << "Horas que pode trabalhar por semana: ";

    cin >> resp;

    if(resp.compare("-1") == 0)
      return false; //user wants to leave

    if(validAnswer(resp, INTEIRO))
      break;
  }

  toInsert.append(resp);

  toInsert.append(" ; ");

  /*GET WEEK MAX WORKLOAD*/

  /*GET REST TIME*/

  while(1)
  {
    cout << "Tempo minimo de descanso entre turnos: ";

    cin >> resp;

    if(resp.compare("-1") == 0)
      return false; //user wants to leave

    if(validAnswer(resp, INTEIRO))
      break;
  }

  toInsert.append(resp);

  /*GET REST TIME*/

  Enterprise.addDriver(toInsert);

  return true;
}

bool removeDriver (Company &Enterprise)
{
  string resp;

  int x;

  system("clear");

  cout << "Insira -1 a qualquer momento para parar remocao\n\n";

  while(1)
  {
    Enterprise.lightShowDrivers();

    cout << "Insira o ID do condutor que pretende remover: ";

    cin >> resp;

    if(resp.compare("-1") == 0)
      return false; //user wants to leave

    if(validAnswer(resp,INTEIRO))
      if((x = Enterprise.CheckDriverId(stoi(resp))) >= 0)
        break;
  }

  Enterprise.deleteDriver((size_t) x);

  return true;
}

bool editDriversData(Company &Enterprise)
{
  string resp, newVal;

  int x;

  system("clear");

  cout << "Insira -1 a qualquer momento para cancelar edicao\n\n";

  while(1)
  {
    Enterprise.lightShowDrivers();

    cout << "Insira o ID do condutor que pretende editar: ";

    cin >> resp;

    if(resp.compare("-1") == 0)
      return false; //user wants to leave

    if(validAnswer(resp,INTEIRO))
      if((x = Enterprise.CheckDriverId(stoi(resp))) >= 0)
        break;
  }

  while(1)
  {
    PrintOptions(Enterprise, EDIT_DRIVER_M, x);

    cin >> resp;

    if(validAnswer(resp, INTEIRO))
    {
      if(stoi(resp) > 0 && stoi(resp) < 7)
        break;
      else if(stoi(resp) == -1)
        return false;
    }
  }

  switch (stoi(resp))
  {
    case 1:
      while(1)
      {
        cout << "Insira o novo identificador: ";
        cin >> newVal;
        if(validAnswer(newVal, INTEIRO))
        {
          if(stoi(newVal) > 0)
          {
            Enterprise.changeDriversettings(x, newVal, ID);
            return true;
          }
          else if(stoi(newVal) == -1)
            return false;
        }
      }
    case 2:
      cout << "Insira o novo nome: ";
      cin.ignore();
      getline(cin, newVal);
      if(newVal.compare("-1") == 0)
        return false;
      else
      {
        Enterprise.changeDriversettings(x, newVal, NOME);
        break;
      }
    case 3:
      while(1)
      {
        cout << "Insira novo limite para as horas de trabalho diarias: ";
        cin >> newVal;
        if(validAnswer(newVal, INTEIRO))
        {
          if(stoi(newVal) > 0)
          {
            Enterprise.changeDriversettings(x, newVal, MAX_DAY_LOAD);
            break;
          }
          else if(stoi(newVal) == -1)
            return false;
        }
      }
    case 4:
      while(1)
      {
        cout << "Insira novo limite para as horas de trabalho semanais: ";
        cin >> newVal;
        if(validAnswer(newVal, INTEIRO))
        {
          if(stoi(newVal) > 0)
          {
            Enterprise.changeDriversettings(x, newVal, MAX_WEEK_LOAD);
            break;
          }
          else if(stoi(newVal) == -1)
            return false;
        }
      }
    case 5:
      while(1)
      {
        cout << "Insira novo tempo minimo de descanso entre turnos: ";
        cin >> newVal;
        if(validAnswer(newVal, INTEIRO))
        {
          if(stoi(newVal) > 0)
          {
            Enterprise.changeDriversettings(x, newVal, REST_TIME_NEEDED);
            break;
          }
          else if(stoi(newVal) == -1)
            return false;
        }
      }
    case 6:
      return false;
  }

  return true;
}

bool driversManagement (Company &Enterprise)
{
  string resp;

  int res;

  PrintOptions(Enterprise, MANAGE_DRIVERS_M, -1);

  cout << "Insira uma opcao: ";

  cin >> resp;

  if(!validAnswer(resp, INTEIRO))
    return true;

  res = stoi(resp);

  switch(res)
  {
    case 1:
      if(addDriver(Enterprise))
        Enterprise.printDiverToFile();
      break;
    case 2:
      if(removeDriver(Enterprise))
        Enterprise.printDiverToFile();
      break;
    case 3:
      if(editDriversData(Enterprise))
        Enterprise.printDiverToFile();
      break;
    case 4:
      return false;
    default:
        return true;
  }

  return true;
}

bool addLine(Company &Enterprise)
{
  Line myLine;
  string myString;


  system("clear");

  cout << "Insira -1 a qualquer momento para parar inserção\n\n";

  while(1)
  {
    cout << "Inserir ID: ";

    cin >> myString;

    if(myString.compare("-1") == 0)
      return false;

    if(validAnswer(myString, INTEIRO))
    {
      if(Enterprise.searchLine(stoi(myString)) >= 0)
        cout << "Esse id ja existe!\n";
      else
        break;
    }
    else
      cout << "Tem de inserir um numero!\n";
  }

  myLine.setID(stoi(myString));

  while(1)
  {
    cout << "Inserir frequencia: ";

    cin >> myString;

    if(myString.compare("-1") == 0)
      return false;

    if(validAnswer(myString, INTEIRO))
    {
      if(stoi(myString) < 0)
        cout << "A frequencia tem de ser um valor positivo!\n";
      else
        break;
    }
    else
      cout << "Tem de inserir um numero!\n";
  }

  myLine.setFreq(stoi(myString));

  cout << "Insira o nome da primeira paragem\n";

  cin.ignore();

  getline(cin, myString);

  if(myString.compare("-1") == 0)
    return false;

  myLine.addStop(myString);

  cout << "Quando nao quiser inserir mais paragens insira um tempo 0\n";

  while(1)
	{
    while(1)
    {
      cout << "Insira o tempo ate a proxima paragem: ";

      cin >> myString;

      if(myString.compare("-1") == 0)
        return false;

      if(validAnswer(myString, INTEIRO))
      {
        if(stoi(myString) < 0)
          cout << "O tempo tem de ser um valor positivo!\n";
        else
          break;
      }
      else
        cout << "Tem de inserir um numero!\n";
    }

    if(myString.compare("0") == 0)
      break;

    myLine.addTime(stoi(myString));

		cout << "Insira o nome da proxima paragem\n";

		cin.ignore();

    if(myString.compare("-1") == 0)
      return false;

  	getline(cin, myString);

		myLine.addStop(myString);
	}

  Enterprise.insertLine(myLine);

  return true;
}

bool removeLine(Company &Enterprise)
{
  string resp;

  int index;

  system("clear");

  cout << "Linhas existentes: \n\n";

  Enterprise.lightShowLines();

  while(1)
  {
    cout << "Insira o id que pretede remover ou -1 para abandonar ";

    cin >> resp;

    if(resp.compare("-1") == 0)
      return false;

    if(validAnswer(resp, INTEIRO))
    {
      if((index = Enterprise.searchLine(stoi(resp))) < 0)
        cout << "Esse id nao existe!\n";
      else
        break;
    }
    else
      cout << "Tem de inserir um numero identificador\n";
  }

  Enterprise.removeLine(index);

  return true;
}

bool linesManagement(Company &Enterprise)
{
  string resp;

  int res;

  PrintOptions(Enterprise, MANAGE_LINES_M, -1);

  cout << "Insira uma opcao: ";

  cin >> resp;

  if(!validAnswer(resp, INTEIRO))
    return true;

  res = stoi(resp);

  if(Enterprise.searchLine(res) >= 0)
  {
    while(resp.compare("-1") != 0)
    {
      Enterprise.showLines(Enterprise.searchLine(res));
      cout << "Inisra -1 para sair\n";
      cin >> resp;
    }

    return true;
  }
  else
  {
    switch(res)
    {
      case 1:
        if(addLine(Enterprise))
          Enterprise.printLineToFile();
        break;
      case 2:
        if(removeLine(Enterprise))
          Enterprise.printLineToFile();
        break;
      case 3:
        Enterprise.changeLines();
        break;
      case 4:
        return false;
      default:
        return true;
    }
  }

  return true;
}

bool timeTable(Company &Enterprise)
{
  string resp;

  int LineIndex;

  PrintOptions(Enterprise, TIMETABLE_M, -1);

  cout << "Insira uma opcao: ";

  cin >> resp;

  if(!validAnswer(resp, INTEIRO))
    return true;

  Enterprise.lightShowLines();

  switch (stoi(resp))
  {
    case 1:
      system("clear");
      Enterprise.lightShowLines();
      cout << endl << endl << "Escreva o identificador da linha que pretende ou -1 para sair: ";
      cin >> resp;
      while(1)
      {
        if(resp.compare("-1") == 0)
          return true;

        if(validAnswer(resp, INTEIRO))
        {
          if((LineIndex = Enterprise.searchLine(stoi(resp))) >= 0)
            break;
          else
            cout << "Insira um identificador dos indicados a cima\n";
        }
        else
          cout << "Insira um numero\n";
      }
      Enterprise.seeSchedule(LineIndex);
      break;
    case 2:
      system("clear");
      PrintOptions(Enterprise, STOP_TIMETABLE_M, -1);
      Enterprise.seeAllStops();
      cout << endl << "Selecione a paragem: ";
      cin >> resp;
      while(1)
      {
        if(resp.compare("-1") == 0)
          return true;

        if(validAnswer(resp, INTEIRO))
        {
          if(stoi(resp) > 0 && stoi(resp) <= (int)Enterprise.getNumBusStops())
            break;
          else
            cout << "Insira um dos numeros indicados a cima\n";
        }
        else
          cout << "Insira um numero\n";
      }
      Enterprise.seeStopSchedule((unsigned int)stoi(resp) + 1);
      break;
    case 3:
      return false;
    default:
      return true;
  }

  return true;
}

bool checksExistence(vector<string> strVect, string str)
{
  for(vector<string>::iterator i = strVect.begin(); i != strVect.end(); i++)
    if(i->compare(str) == 0)
      return true;

  return false;
}

void linesWithStop(Company &Enterprise)
{
  vector<Line> allLines = Enterprise.getLines();

  vector<string> aux, allStops;

  vector<int> allLinesId;

  int indice = 1;

  string resp;

  cout << "Insira -1 para voltar a qualquer momento ao menu anterior" << endl;

  for(vector<Line>::iterator i = allLines.begin(); i != allLines.end(); i++)
  {
    aux = i->getBusStops();

    for(vector<string>::iterator j = aux.begin(); j != aux.end(); j++)
    {
      allStops.push_back(*j);

      cout << right << setw(2) << indice << " - " << left << *j << endl;

      indice++;
    }
  }

  while(1)
  {
    cout << "Selecione a paragem: ";

    cin >> resp;

    if(resp.compare("-1") == 0)
      return;
    else if(validAnswer(resp,INTEIRO))
    {
      if(stoi(resp) > 0 && (unsigned int)stoi(resp) <= Enterprise.getNumBusStops())
      {
        allLinesId = Enterprise.getLinesWithStop(allStops.at(stoi(resp) - 1));
        break;
      }
      else
        cout << "Insira uma das opcoes ou o nome duma paragem!\n";
    }
  }

  while(1)
  {
    if(allLinesId.size() > 1)
    {
      cout << "Na paragem " << allStops.at(stoi(resp) - 1) << " passam autocarros das seguintes linhas: ";

      for(size_t i = 0; i < allLinesId.size(); i++)
      {
        if(i == allLinesId.size() - 1)
          cout << allLinesId[i] << endl;
          else
          cout << allLinesId[i] << ", ";
      }

      cout << "( " << allLinesId.size() << " linhas)";

      cout << endl << "Insira -1 para sair!\n";

      cin >> resp;

      if(resp.compare("-1") == 0)
        break;
    }
    else
    {
      cout << "Na paragem " << allStops.at(stoi(resp) - 1) << " passa um autocarro da linha " << allLinesId[0] << " .\n";

      cout << endl << "Insira -1 para sair!\n";

      cin >> resp;

      if(resp.compare("-1") == 0)
        break;
    }
  }
}

void travelBetweenStops(Company &Enterprise)
{
  vector<Line> allLines = Enterprise.getLines();

  vector<string> aux, allStops;

  vector<int> allLinesId;

  int indice = 1;

  string resp;

  system("clear");

  cout << "Insira -1 para voltar a qualquer momento ao menu anterior" << endl;

  for(vector<Line>::iterator i = allLines.begin(); i != allLines.end(); i++)
  {
    aux = i->getBusStops();

    for(vector<string>::iterator j = aux.begin(); j != aux.end(); j++)
    {
      allStops.push_back(*j);

      cout << right << setw(2) << indice << " - " << left << *j << endl;

      indice++;
    }
  }

  while(1)
  {
    cout << "Escolha duas paragens separadas por ' ' espaco: ";

    resp.clear();

    cin.ignore();

    getline(cin, resp);

    if(resp.find(' ') == resp.npos)
      cout << "Introduza novamente\n";
    else
    {
      aux = allLines.at(0).tokenizer(resp, " ");

      if(validAnswer(aux[0],INTEIRO) && validAnswer(aux[1],INTEIRO))
      {
        if(stoi(aux[0]) > 0 && stoi(aux[0]) <= (int)Enterprise.getNumBusStops() && stoi(aux[1]) > 0 && stoi(aux[1]) <= (int)Enterprise.getNumBusStops())
          break;
        else
          cout << "Insira dois numeros dos indicados a cima\n";
      }
      else
        cout << "Introduza dois inteiros\n";
    }
  }

  Enterprise.calculateTrip(Enterprise.getLineIndexOfStop(stoi(aux[0])), allStops.at(stoi(aux[0]) - 1), Enterprise.getLineIndexOfStop(stoi(aux[1])), allStops.at(stoi(aux[1]) - 1));
}

bool Plan(Company &Enterprise)
{
  string resp;

  while(1)
  {
    system("clear");

    PrintOptions(Enterprise,PLAN_TRIP_M, -1);

    cin >> resp;

    if(resp.compare("-1") == 0)
      return false;

    if(validAnswer(resp, INTEIRO))
      break;
    else
      cout << "Insira um numero\n";
  }

  switch (stoi(resp))
  {
    case 1:
      linesWithStop(Enterprise);
      break;
    case 2:
      travelBetweenStops(Enterprise);
      break;
    case 3:
      return false;
    default:
      return true;
  }

  return true;
}
bool Interface(Company &Enterprise)
{
  string resp;

  edited = false;

  int res = -1;

  while(res == -1)
  {
    PrintOptions(Enterprise, MAIN_M,-1);

    cout << "Insira uma opcao: ";

    cin >> resp;

    if(validAnswer(resp, INTEIRO))
      break;

    cout << "Opcao invalida!\n";
  }

  res = stoi(resp);

  switch (res)
  {
    case 1:
      while(driversManagement(Enterprise));
      break;
    case 2:
      while(linesManagement(Enterprise));
      break;
    case 3:
      while(timeTable(Enterprise));
      break;
    case 4:
      while(Plan(Enterprise));
      break;
    case 5:
      return false;
    default:
      return true;
  }

  return true;
}
