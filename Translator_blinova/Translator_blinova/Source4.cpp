#include <iostream>
#include <fstream>
#include <string>
#include "Header.h"

void solution4(string dictionary_name, string out_name, char params_char, int params_num, string params_string) {

	int N = 44643;
	string* A = new string[N]; // ���������� ������� ������

	ifstream fin;
	fin.open(dictionary_name, ios::in);

	if (!fin.is_open()) {
		cout << "������ �������� �����" << endl;
	}
	else {
		cout << "������ �����..." << endl;
		int l = 0;
		while (!fin.eof()) {
			getline(fin, A[l]); //��������� ������ �� �����
			l++;
		}
	}
	fin.close();

	ofstream fout;
	fout.open(out_name, ios::out);

	char letter = A[0][0], b, f;
	fout << A[0] << endl;
	for (int i = 1; i < N; i++) {
		b = letter - 32; //��������� ����� �� letter
		f = A[i][0];
		if (A[i][0] != letter && A[i][0] != (letter - 32)) {
			fout << A[i] << endl;
			if (A[i][0] != (letter - 32)) letter = A[i][0]; // ������ �����
		}
	}
	fout.close();
	delete[] A;
}