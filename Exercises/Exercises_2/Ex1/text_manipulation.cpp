#include "text_manipulation.h"

#define INTEIRO -100
#define DECIMAL -200
#define U_INTEIRO -300

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

	while ((found = to_token.find(token, last_found + 1)) != to_token.npos)
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
    case U_INTEIRO:
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
      if(stoi(answer) < 0)
        return false;
      break;
  }

  return true;
}
