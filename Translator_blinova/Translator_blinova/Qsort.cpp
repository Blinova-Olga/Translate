#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void Quick_sort(string* a, int l, int r)
{
	int i = l, j = r;
	string w;
	int k = (l + r) / 2;
	string pivot = a[k].substr(a[k].find_first_of(':') + 1, string::npos); // �������� ������� �����
	while (i <= j)
	{
		while (a[i].substr(a[i].find_first_of(':') + 1, string::npos).compare(pivot) < 0) i++; // ���� a[i] ���� �� ��������, ��� pivot
		while (a[j].substr(a[j].find_first_of(':') + 1, string::npos).compare(pivot) > 0) j--;// ���� a[i] ���� �� ��������, ��� pivot
		if (i <= j) {
			w = a[i];
			a[i] = a[j];
			a[j] = w;
			i++;
			j--;
		}
	}

	if (i < r)
		Quick_sort(a, i, r);
	if (l < j)
		Quick_sort(a, l, j);
}
