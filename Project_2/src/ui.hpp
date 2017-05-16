#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Company.h"
#include "Line.h"
#include "Driver.h"
#include "Shift.h"

#define INTEIRO 100
#define DECIMAL 200

#define MAIN_M 10001
#define MANAGE_DRIVERS_M 10011
#define EDIT_DRIVER_M 10012
#define MANAGE_LINES_M 10021
#define TIMETABLE_M 10031
#define STOP_TIMETABLE_M 10032
#define PLAN_TRIP_M 10041

using namespace std;

/*Recebe os nomes dos ficheiros*/
vector<string> getFilesName();

/*imprime as opcoes para o utilizador*/
void PrintOptions (Company &Enterprise, int menu, int option);

/*verifica se a resposta que o utilizador inseriu e valida*/
bool validAnswer(string answer, int type);

/*interacao com o utilizador para adicionar um condutor*/
bool addDriver (Company &Enterprise);

/*interacao com o utilizador para a remocao de um condutor*/
bool removeDriver (Company &Enterprise);

/*Interacao com o utilizador para editar informacao dum condutor*/
bool editDriversData(Company &Enterprise);

/*Interacao com o utilizador para decidir se e para adicionar, eliminar ou editar um condutor*/
bool driversManagement (Company &Enterprise);

/*interacao com o utilizador para adicionar uma linha*/
bool addLine(Company &Enterprise);

/*Interacao com o utilizador para decidir se e para adicionar, eliminar ou editar uma linha*/
bool linesManagement(Company &Enterprise);

/*Utilizador seleciona a linha que pretende visualizar*/
void showLineTimeTable(Company &Enterprise);

/*Interacao com o utilizador para mostrar horarios*/
bool timeTable(Company &Enterprise);

/*Verifica se uma string faz parte do vetor strVect*/
bool checksExistence(vector<string> strVect, string str);

/*Interacao com o utilizador para mostrar linhas que contém uma certa paragem*/
void linesWithStop(Company &Enterprise);

/*Interacao com o utilizador para tentar arranjar percurso entre duas paragens*/
void travelBetweenStops (Company &Enterprise);

/*Interacao com o utilizador para planeamento de viagens*/
bool Plan(Company &Enterprise);

/*interacao do menu inicial*/
bool Interface (Company &Enterprise);
