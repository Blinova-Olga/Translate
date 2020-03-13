#include <iostream>
#include <fstream>
#include <string>
#include "Header.h"

void solution7(string dictionary_name, string out_name, char params_char, int params_num, string params_string) {

	int N = 44643;
	string* A = new string[N]; // Объявление массива данных

	ifstream fin;
	fin.open(dictionary_name, ios::in);

	if (!fin.is_open()) {
		cout << "Ошибка открытия файла" << endl;
	}
	else {
		cout << "Чтение файла..." << endl;
		int l = 0;
		while (!fin.eof()) {
			getline(fin, A[l]); //получение строки из файла
			l++;
		}
	}
	fin.close();

	ofstream fout;
	fout.open(out_name, ios::out);

	int n;
	for (int i = 0; i < N; i++) {
		n = A[i].find_first_of(':'); // длина английского слова 
		if (n == params_num) {
			fout << A[i] << endl;
		}
	}
	fout.close();
	delete[] A;

}