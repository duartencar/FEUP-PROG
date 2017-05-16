#pragma once

#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

#define FOWARD 111111
#define BACKWARD 0000001
#define START_HOUR 480
#define END_HOUR 1230

class Line
{
 public:
   /*default constructor*/
   Line();

   /*constructor*/
   Line(string textLine);

   /*retorna um token*/
   string get_token(string to_token, size_t begin, size_t end);

   /*retorna um vetor com todos os tokens(strings)*/
   vector<string> tokenizer (string to_token, string token);

   /*retorna um vetor com todos os tokens(inteiros)*/
   vector<int> int_tokenizer (string to_token, string token);

   /*retorna o numero identificadpr da linha*/
   unsigned int getId() const;

   /*retorna a frequencia da linha*/
   unsigned int getFreq() const;

   /*retorna o numero de paragens que ha numa linha*/
   unsigned int getNumStops() const;

   /*retorna o indice duma paragem no vetor*/
   unsigned int getStopIndex(string stop) const;

   /*retorna um vector com o nome de todas as paragens da linha*/
   vector<string> getBusStops() const;

   /*retorna um vetor com os tempos entre paragens da linha*/
   vector<int> getTimings() const;

   /*altera o valor de id para ID*/
   void setID(int ID);

   /*altera o valor de freq para Freq*/
   void setFreq(int Freq);

   /*e designado um novo vetor de paragens*/
   void setStops(vector<string> newStops);

   /*e designado um novo vetor de tempos*/
   void setTimings(vector<int> newTimings);

   /*copia para a linha todas as informacoes de outra linha*/
   void copy(Line lineToCopy);

   /*adiciona uma paragem ao vetor de paragens*/
   void addStop(string newStop);

   /*adiciona um tempo ao vetor de tempos*/
   void addTime(int newTime);

   /*calcula o tempo total de viagem na linha*/
   unsigned int totalTime();

   /*calcula o tempo ate uma paragem indicada pelo o indice stop*/
   unsigned int totalTime(size_t stop, int way);

   /*retorna o tempo entre duas paragens*/
   unsigned int totalTime(size_t begin, size_t end);

   /*apresenta toda a informacao duma paragem*/
   void info();

   /*apresenta toda a informacao duma paragem*/
   void showLineInfo();

   /*retorna o numero de letras do maior nome duma paragem da linha*/
   unsigned int getNameLength();

   /*retorna o maior tamanho dum nome duma paragem*/
   int getNameLength(int pos);

   /*apresenta informacao reduzida duma paragem*/
   void lightInfo(int primeira, int ultima);

   /*Interage com o utilizador para mudar o nome duma paragem*/
   void changeBusStops();

   /*mostra as paragens duma linha*/
   void showBusStops();

   /*altera um tempo entre paragens*/
   void changeTimesList();

   /*mostra os tempos entre paragens*/
   void showTimesList();


 private:
   unsigned int id;              /*Identificador da linha*/
   unsigned int freq;            /*Frequencia de partida de autocarros*/
   unsigned int numberOfBus;     /*Numero de diferentes autocarros duma linha*/
   unsigned int shiftPerDay;     /*Numero de turnos a realizar num dia*/
   vector<string> busStopList;   /*Vetor com todas as paragens de autocarros*/
   vector<int> timesList;        /*Vetor com tempos entre paragens*/
};
