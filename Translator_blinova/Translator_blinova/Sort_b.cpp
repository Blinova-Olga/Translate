#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void sort_B_C(string* a, int* c, int l, int r)
{
	int i = l, j = r;
	string w;
	int v;
	int k = (l + r) / 2;
	string pivot = a[k]; // �������� ������� �����

	while (i <= j)
	{
		while (a[i].compare(pivot) < 0) i++; // ���� a[i] ���� �� ��������, ��� pivot
		while (a[j].compare(pivot) > 0) j--;// ���� a[i] ���� �� ��������, ��� pivot
		if (i <= j) {
			w = a[i];
			v = c[i];
			a[i] = a[j];
			c[i] = c[j];
			a[j] = w;
			c[j] = v;
			i++;
			j--;
		}
	}

	if (i < r)
		sort_B_C(a, c, i, r);
	if (l < j)
		sort_B_C(a, c, l, j);



}
