#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>


using namespace std;

class Shift
{
  public:
    /*default constructor*/
    Shift();

    /*Contructor*/
    Shift(unsigned int linha, unsigned int condutor, unsigned int autocarro, unsigned int inicio, unsigned int fim);

    /*retorna a linha a que este turno pertence*/
    unsigned int getBusLineId() const;

    /*retorna o id do condutor que esta a fazer o turno*/
    unsigned int getDriverId() const;

    /*retorna o numero de ordem do autocarro que esta a fazer este turno*/
    unsigned int getBusOrderNumber() const;

    /*retorna as horas de começo dum turno*/
    unsigned int getStartTime() const;

    /*retorna as horas de fim dum turno*/
    unsigned int getEndTime() const;

    /*modifica o id do autocarro que esta a fazer o turno*/
    void setBusLineId(unsigned int busLineId);

    /*modifica o id do condutor a que pertence o turno*/
    void setDriverId(unsigned int driverId);

    /*modifica o numero de ordem do autocarro que esta a fazer a linha*/
    void setBusOrderNumber(unsigned int busOrderNumber);

    /*modifica o valor das horas de comeco do turno*/
    void setStartTime(unsigned int startTime);

    /*modifica o valor das horas de acabamento do turno*/
    void setEndTime(unsigned int endTime);

    /*retorna  a duracao do turno*/
    unsigned int duration();

    /*retorna string com hora formatada*/
    string convertToHours(unsigned int to_convert);

    /*imprime informacoes sobre um turno*/
    void printShift();

  private:
    unsigned int busLineId;       //Identificador da linha a que pertence este turno
    unsigned int driverId;        //Identificador do condutor a que pertence este turno
    unsigned int busOrderNumber;  //numero de ordem do autocarro da linha
    unsigned int startTime;       //horas de comeco do turno
    unsigned int endTime;         //horas a que o turno acaba
};
