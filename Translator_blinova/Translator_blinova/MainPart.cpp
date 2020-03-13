#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include "Header.h"
using namespace std;


int main(int argc, char** argv)
{
	setlocale(LC_ALL, "ru-RU");
	int N = 44645;
	string dictionary_name = argv[1];
	string out_name = argv[2];
	int num=1;
	if (strlen(argv[3]) == 1) { num = argv[3][0] - 48; }
	if (strlen(argv[3]) == 2) { num = 10; }
	char params_char='a';
	int params_num=1;
	string params_string="aaa";
	if (argc >4) params_char = argv[4][0];
	if (argc >5) params_num= argv[5][0]-48;
	if (argc >6) params_string= argv[6];
	
	void((*arr[10]))(string q, string w, char e, int r, string t);
	arr[0] = solution1;
	arr[1] = solution2;
	arr[2] = solution3;
	arr[3] = solution4;
	arr[4] = solution5;
	arr[5] = solution6;
	arr[6] = solution7;
	arr[7] = solution8;
	arr[8] = solution9;
	arr[9] = solutionX;
	
	arr[num - 1](dictionary_name, out_name, params_char, params_num, params_string);

	cout << "Конец выполнения прогрaммы" << endl;

	return 0;
}
