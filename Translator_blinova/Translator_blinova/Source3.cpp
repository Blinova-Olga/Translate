// params_char = 'r' или 'e' в зависимости от языка
//params_num - количество одинаковых символов
//params_string - позиция :
		//params_string = "begin" или "end"
		//params_string = любой другой строчке с желаемым количеством символов, обозначающим позицию


#include <iostream>
#include <fstream>
#include <string>
#include "Header.h"

void solution3(string dictionary_name, string out_name, char params_char, int params_num, string params_string) {

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
		while (!fin.eof() && l < N) {
			getline(fin, A[l]); //получение строки из файла
			l++;
		}
	}
	fin.close();

	ofstream fout;
	fout.open(out_name, ios::out);

	int chouse;//позиция
	if (params_string == "begin") chouse = 0;
	else {
		if (params_string == "end") chouse = -1;
		else
		{
			chouse = params_string.size();
		}
	}
	unsigned int len = abs(params_num);
	string h;

	string* B = new string[N];
	int* C = new int[N];
	for (int i = 0; i < N; i++) {
		C[i] = i;
	}


	
	if (params_char == 'r') {
		if (chouse == -1) {

			for (int i = 0; i < N; i++) {
				if (len <= A[i].size() - A[i].find_first_of(':') - 1 && A[i] != "") {
					B[i] = A[i].substr(A[i].size() - len, string::npos);
				}
				else B[i] = "";
			}

			sort_B_C(B, C, 0, N - 1);

		}
		else if (chouse >= 0) {

			for (int i = 0; i < N; i++) {
				if (len <= A[i].size() - (A[i].find_first_of(':') + 1 + chouse) && A[i] != "") {
					B[i] = A[i].substr(A[i].find_first_of(':') + 1 + chouse, len);
				}
				else B[i] = "";
			}

			sort_B_C(B, C, 0, N - 1);

		}

	}
	else {
		if (params_char == 'e') {
			if (chouse == -1) {

				for (int i = 0; i < N; i++) {
					if (len <= A[i].find_first_of(':') && A[i] != "") {
						B[i] = A[i].substr(A[i].find_first_of(':') - len, len);
					}
					else B[i] = "";
				}

				sort_B_C(B, C, 0, N - 1);

			}
			else if (chouse >= 0) {
				for (int i = 0; i < N; i++) {
					if (len <= A[i].find_first_of(':') - chouse && A[i] != "") {
						B[i] = A[i].substr(chouse, len);
					}
					else B[i] = "";
				}

				sort_B_C(B, C, 0, N - 1);
			}
		}
		else cout << "Ввеён неправельный язык" << endl;
	}
	int q = 0;
	while (B[q] == "") q++;
	string comp;
	if (q >= N) cout << "Не нашлось ни одного элемента удовлетворяющего условию" << endl;
	else {
		comp = B[q];
		q++;
	}



	for (int i = q; i < N; i++) {
		if (B[i] == comp) {
			fout << A[C[i - 1]] << endl;
			fout << A[C[i]] << endl;
			while (B[i + 1] == comp) {
				fout << A[C[i + 1]] << endl;
				i++;
			}

		}
		else {
			comp = B[i];
		}
	}

	
	fout.close();


	delete[] A;
	delete[] B;
	delete[] C;

}