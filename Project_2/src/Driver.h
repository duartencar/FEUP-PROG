#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "Shift.h"

using namespace std;

class Driver
{
 public:
   /*default constructor*/
   Driver();

   /*Constructor*/
   Driver(string textLine);

   /*retorna um token*/
   string get_token(string to_token, size_t begin, size_t end);

   /*retorna um vetor com todos os tokens(strings)*/
   vector<string> tokenizer (string to_token, string token);

   /*retorna um vetor com todos os tokens(inteiros)*/
   vector<int> int_tokenizer (string to_token, string token);

   /*retorna o identificador de um condutor*/
   unsigned int getId() const;

   /*retorn o nome dum condutor*/
   string getName() const;

   /*retorna a duracao maxima dum turno*/
   unsigned int getShiftMaxDuration() const;

   /*retorna o tempo maximo que um condutor pode trabalhar por semana*/
   unsigned int getMaxWeekWorkingTime() const;

   /*retorna o tempo minimo de descanso entre turnos*/
   unsigned int getMinRestTime() const;

   /*retorna um vetor de turnos atribuidos ao condutor*/
   vector<Shift> getShifts() const;

   /*Altera o id do condutor para newID*/
   void setId(unsigned int newID);

   /*altera o nome do condutor para newName*/
   void setName(string newName);

   /*Altera o maxima duracao de um turno para newMaxHours*/
   void setMaxHours(unsigned int newMaxHours);

   /*Altera o maximo de horas semanais para newMaxWeekWorkingTime*/
   void setMaxWeekWorkingTime(unsigned int newMaxWeekWorkingTime);

   /*Altera o tempo minimo de descanso entre turnos para newMinRestTime*/
   void setMinRestTime(unsigned int newMinRestTime);

   /*Mostra a informacao completa dum condutor*/
   void info();

   /*Mostra apenas o id e o nome do condutor*/
   void lightInfo();

   
private:
  unsigned int id;                 /*Identificador do condutor*/
  string name;                     /*Nome do condutor*/
  unsigned int maxHours;           /*Maxima duracao dum turno*/
  unsigned int maxWeekWorkingTime; /*Tempo maximo que um condutor pode trabalhar por semana*/
  unsigned int minRestTime;        /*Tempo minimo de descanso entre turnos*/
  vector<Shift> shifts;            /*Turnos atribuidos*/
};
