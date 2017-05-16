#pragma once

#include <iostream>
#include <vector>

#include "Shift.h"


using namespace std;

class Bus
{
 public:
    /*default constructor*/
    Bus();

    /*Contructor*/
    Bus(unsigned int order, unsigned int driver, unsigned int line);

    /*retorna o valor de ordem dum autocarro*/
    unsigned int getBusOrderInLine() const;

    /*retorna o id do motorista que conduz este autocarro*/
    unsigned int getDriverId() const;

    /*retorna a linha uqe este autocarro esta a percorrer*/
    unsigned int getLineId() const;

    /*retorna o vetor de turnos*/
    vector<Shift> getSchedule() const;

    /*altera o condutor que conduz este autocarro*/
    void setDriverId(int newID);

    /*Altera a linha que este autocarro esta a percorrer*/
    void setLineId(int newID);

    /*altera o numero de ordem deste autocarro*/
    void setOrder(int newOrder);

private:
  unsigned int orderInLine; //Valor de ordem do autocarro
  unsigned int driverId;    //Identificador do condutor que o conduz
  unsigned int lineId;      //Identificador da linha que o autocarro esta a percorrer
  vector<Shift> schedule;   //Vetor de turnos
};
