#pragma once

#include <vector>
#include <string>
#include <iostream>

using namespace std;

string get_token(string to_token, size_t begin, size_t end); //returns tokens

vector<string> tokenizer (string to_token, string token); //gets token posititions and returns them

vector<int> int_tokenizer (string to_token, string token);

/*verifica se a resposta que o utilizador inseriu e valida*/
bool validAnswer(string answer, int type);
