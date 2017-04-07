#include "text_manipulation.h"

using namespace std;

string get_token(string to_token, size_t begin, size_t end)
{
  string tokenized;

  for(size_t i = begin; i < end; i++)
    tokenized.push_back(to_token.at(i));

  return tokenized;
}

vector<string> tokenizer (string to_token, string token)
{
  size_t found, last_found = -1;

  vector<string> tokens;

  while((found = to_token.find(token,last_found + 1)) != to_token.npos)
  {
    tokens.push_back(get_token(to_token, last_found + 1, found));
    last_found = found;
  }

  tokens.push_back(get_token(to_token, last_found + 1, to_token.size()));

  return tokens;
}

vector<int> int_tokenizer (string to_token, string token)
{
  vector<string> to_convert;
  vector<int> to_return;

  to_convert = tokenizer(to_token, token);

  for(int i = 0; i < (int)to_convert.size(); i++)
    to_return.push_back(stoi(to_convert[i]));

  return to_return;
}

void line_info (line a)
{
  int sum = 0;

  cout << endl << "Linha -> " << a.identifier << endl;

  cout << "Frequencia de passagem: " << a.freq << " minutos.\n";

  cout << "Passa em:\n";

  for(int i = 0; i < (int)a.stops.size(); i++)
    cout << "\t" << a.stops[i] << endl;

  for(int i = 0; i < (int)a.times.size(); i++)
    sum += a.times[i];

  cout << "Tempo total da viagem e de " << sum << " minutos\n" << endl << endl;
}
