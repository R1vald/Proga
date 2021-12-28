#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

int NOD(int a, int b, int c); int NOD(int a, int b);
int NOD_REC(int a, int b);

int main()
{
	setlocale(LC_ALL, "rus");
	int num_1, num_2, num_3, x, y, d;
	cout << "������� ������ �����: "; cin >> num_1; cout;
	cout << "������� ������ �����: "; cin >> num_2; cout;
	cout << "������� ������ �����: "; cin >> num_3; cout << endl << endl;
	if (num_1 == 0 || num_2 == 0 || num_3 == 0) { cout << "���� �� ����� ��������� 0!" << endl; return main(); }
	else
	{
		cout << "��� ������ 3-� �����: " << NOD(num_1, num_2, num_3) << endl;
		cout << "��� ������ 2-� �����: " << NOD(num_1, num_2) << endl << endl;
		cout << "����������� ������� ���������� ���:" << NOD_REC(num_1, num_2) << endl;
	}
	return 0;
}

int NOD(int a, int b, int c)
{
	int delimoe, delitel, r = 0, delimoe_fake;

	if (a >= b) { delimoe = a; delitel = b; }//proverka
	else { delimoe = b; delitel = a; }
	int ostatok = delitel;
	do
	{
		if (r == 0) r++;
		else delimoe = delitel;
		delitel = ostatok;
		ostatok = delimoe % delitel;

	} while (ostatok != 0);
	if (delitel >= c) { delimoe = delitel; delitel = c; } //proverka
	else { delimoe = c; }

	ostatok = delitel; r = 0;
	do
	{
		if (r == 0) r++;
		else delimoe = delitel;
		delitel = ostatok;
		ostatok = delimoe % delitel;

	} while (ostatok != 0);

	return delitel;
}
int NOD(int a, int b)
{
	int delimoe, delitel, r = 0, delimoe_fake;

	if (a >= b) { delimoe = a; delitel = b; } // ��������
	else { delimoe = b; delitel = a; }
	int ostatok = delitel;
	do
	{
		if (r == 0) r++;
		else delimoe = delitel;
		delitel = ostatok;
		ostatok = delimoe % delitel;
	} while (ostatok != 0);
	return delitel;
}

int NOD_REC(int a, int b)
{
	if (a % b == 0) return b;
	if (b % a == 0) return a;
	if (a > b) return NOD_REC(a % b, b);
	return NOD_REC(a, b % a);
}

