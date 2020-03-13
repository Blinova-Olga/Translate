#include <iostream>
#include <fstream>
#include <string>
#include "Header.h"

void solution6(string dictionary_name, string out_name, char params_char, int params_num, string params_string) {

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

	Quick_sort(A, 0, N - 1);

	for (int i = 0; i < N; i++) {
		if (!A[i].empty()) fout << A[i] << endl; // ���� ������� �� ������ �������
	}

	fout.close();
	delete[] A;
}