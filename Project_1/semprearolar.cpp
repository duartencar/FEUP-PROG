#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string.h>
#include "text_manipulation.h"

using namespace std;

int main(void)
{
	ifstream lines_file, drivers_file;

	string input;

	stringstream ss;

  vector<string> line_tok;

	vector<line> traffic_network;

	int n_lines = 0;

	lines_file.open("linhas.txt");
	drivers_file.open("condutores.txt");

	if (!lines_file.is_open())
	{
		cerr << "File linhas.txt not found !\n";
		return 1;
	}

	if (!drivers_file.is_open())
	{
		cerr << "File condutores.txt not found !\n";
		return 1;
	}

	while (getline(lines_file, input))
	{
    line_tok = tokenizer(input, ";");

		traffic_network.push_back(line());

		traffic_network[n_lines].identifier = stoi(line_tok[0]);

		traffic_network[n_lines].freq = stoi(line_tok[1]);

		traffic_network[n_lines].stops = tokenizer(line_tok[2], ",");

		traffic_network[n_lines].times = int_tokenizer(line_tok[3], ",");

		n_lines++;
	}

	for(int i = 0; i < n_lines; i++)
		line_info(traffic_network[i]);

	cout << endl;

	return 0;
}
