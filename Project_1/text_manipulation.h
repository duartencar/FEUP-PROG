#ifndef _TEXT_MANIPULATION_H_
#define _TEXT_MANIPULATION_H_

using namespace std;

string get_token(string to_token, size_t begin, size_t end);

vector<string> tokenizer (string to_token, string token);

vector<int> int_tokenizer (string to_token, string token);

#endif
