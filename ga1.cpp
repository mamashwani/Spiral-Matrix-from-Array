#include <iostream>
#include <fstream>
#include "ArgumentManager.h"
#include <string>
#include <cmath>

using namespace std;

//Group 8O 13

int main(int argc, char *argv[])
{

	ArgumentManager am(argc, argv);
	string input = am.get("input");
	string output = am.get("output");

	ifstream ifs(input);
	ofstream ofs(output);

	string line;

	getline(ifs, line);

	int a = ceil(sqrt(line.length()));
	int count = 0;
	int rowS = 0;
	int len = a;

	char **L = new char*[a + 1]; //Dynamic array to store 
	for (int i = 0; i < a + 1; i++)
	{
		L[i] = new char[a + 1]();
	}
	for (int i = 0; i < a + 1; i++)
		for (int j = 0; j < a + 1; j++)
		{
			L[i][j] = 'o';
		}

	while (count < a*a)
	{
		for (int i = rowS; i < len; i++) //first row 
		{
			if (count > line.length() - 1) {
				L[rowS][i] = '.';
			}
			else {
				L[rowS][i] = line[count];
			}
			count++;
		}
		for (int i = rowS + 1; i < len; i++) //last column 
		{
			if (count > line.length() - 1) {
				L[i][len - 1] = '.';
			}
			else {
				L[i][len - 1] = line[count];
			}
			count++;
		}
		for (int i = len - 2; i >= rowS; i--)     //last row
		{
			if (count > line.length() - 1) {
				L[len - 1][i] = '.';
			}
			else {
				L[len - 1][i] = line[count];
			}
			count++;
		}
		for (int i = len - 2; i > rowS; i--)      //first column
		{
			if (count > line.length() - 1) {
				L[i][rowS] = '.';
			}
			else {
				L[i][rowS] = line[count];
			}
			count++;
		}
		rowS++; //increments
		len = len - 1;
	}

	for (int i = 0; i < a; i++)             //print
	{
		for (int j = 0; j < a; j++)
		{
			ofs << L[i][j];
		}
		ofs << '\n';
	}

	return 0;
}