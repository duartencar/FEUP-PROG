#pragma once

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include "Line.h"
#include "Driver.h"

#define NOME 1000
#define ID 2000
#define MAX_DAY_LOAD 3000
#define MAX_WEEK_LOAD 4000
#define REST_TIME_NEEDED 5000
#define FOWARD 111111
#define BACKWARD 0000001

using namespace std;

class Company
{
  public:
    /*defalut constructor*/
    Company ();

    /*constructor*/
    Company (string name , string fichCondutores, string fichLinhas);

    /*retorna o nome da companhia*/
    string getNome() const;

    /*muda o nome da  empresa para myName*/
    void setNome(string myName);

    /*preenche o vetor de linhas*/
    void setLineVector(string myFile);

    /*preenche o vetor condutores*/
    void setDriverVector(string myFile);

    /*uncao que implementa a afectacao de servico*/
    vector<Line> getLines() const;

    /*retorna um vetor com todos os identificadores  que contém uma certa paragem*/
    vector<int> getLinesWithStop(string stop) const;

    /*mostra todas as linhas*/
    void showLines();

    /*mostra a linha i*/
    void showLines(int i);

    /*mostra todos os condutores*/
    void showDrivers();

    /*mostra o condutor i*/
    void showDrivers(int i);

    /*mostra nome e ID de todos os condutores*/
    void lightShowDrivers();

    /*mostra nome e ID de um certo condutor*/
    void lightShowDrivers(int i);

    /* mostra o nome da paragem com mais letras*/
    int getMaxNameLenght(size_t pos);

    /*mostra id, primeira-ultima (paragem) de todas as linhas*/
    void lightShowLines();

    /*mostra id, primeira-ultima (paragem) duma linha*/
    void lightShowLines(int i);

    /*adiciona um condutor ao vetor de condutores*/
    void addDriver (string toInsert);

    /*verifica se ja existe um certo id, retorna -1 se nao existir, id se existir*/
    int CheckDriverId (unsigned int x);

    /*elimmina um condutor na posicao index do vetor*/
    void deleteDriver (size_t index);

    /*altera o um dado do condutor conforme option, para newValue*/
    void changeDriversettings (int DriverIndex, string newValue, int option);

    /*Insere uma linha*/
    void insertLine(Line newLine);

    /*verifica se myID existe*/
    int searchLine(int myID);

    /*Alterar linha*/
    void changeLines();

    /*elimina linha*/
    void removeLine(int i);

    /*atualiza ficheiro de linhas*/
    void printLineToFile();

    /*atualiza ficheiro de condutores*/
    void printDiverToFile();

    /*devolve uma string com o formato mm:ss (5 caracteres)*/
    string convertToHours(unsigned int to_convert);

    /*Imprime as paragens da tabela*/
    void printStopsHeader(vector<string> stops, int width, int way);

    /*Imprime as paragens da tabela a partir duma dada paragem*/
    void printStopsHeader(vector<string> stops, int width, int way, int startingStop);

    /*retorna o nume de paragens existentes*/
    unsigned int getNumBusStops () const;

    /*imprime todas as Paragens da companhia com numeracao*/
    void seeAllStops();

    /*permite a visualizacao das horas a que passam autocarros numa paragem*/
    void seeStopSchedule(unsigned int selectedStop);

    /*premite a visualizacao do horario*/
    void seeSchedule(int LineIndex);

    /*devolve o indice da linha que contem a paragem stopIndex*/
    int getLineIndexOfStop(int stopIndex);

    /*Troca a linha indicada por firstIndex com secondIndex*/
    void switchLines(size_t firstIndex, size_t secondIndex);

    /*Imprime as pissibilidades de viagem entre duas paragens*/
    void calculateTrip(int first, string origin, int second, string destination);

  private:
    string nome;                    //nome da empresa
    vector<Driver> condutores;      //vetor de condutores
    vector<Line> linhas;            //vetor de linhas
};
