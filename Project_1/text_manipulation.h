#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

typedef struct
{
	int identifier;
	int freq;
	vector<string> stops;
	vector<int> times;
} line;

typedef struct
{
	string name;
	vector<int> lines;
} stop;

typedef struct
{
	string name;
	int identifier;
	int hours_p_day;
	int hours_p_week;
	int rest_hours;
} driver;

string get_token(string to_token, size_t begin, size_t end);

vector<string> tokenizer (string to_token, string token);

vector<int> int_tokenizer (string to_token, string token);

void line_info (line a);
