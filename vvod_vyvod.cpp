/*�������� ��������� ������� ����������� ���������.
���������� ������ ���� � 10 ��������, �������� - 4 �����,������� ��������� ��������*/
#include<iostream>
#include<math.h>
#include <iomanip> // ������ ���������� �������� �������� ��� �������������

using namespace std;
void create();// ���� ������ ��� ���������� ����������� ��������� 
double insert();// ������ "�� ������"
bool isTypeCorrect();// �������� �� ������������ ��������� ������ ����
int inputNum(int left_range, int right_range);// ���� ������ ������ 
// --------------------------------------------------------------------//
void main() {
	setlocale(LC_ALL, "rus");
	create();
	while (true)
	{
		cout << " ----------����� ����------------ " << endl
			<< "1.������ ��� ���� �������� ��� �������������  " << endl
			<< "0.����� �� ���������" << endl
			<< "��� �����:";
		int choice;
		choice = inputNum(0, 1);
		switch (choice)
		{
		case 0:system("cls"); return;
		case 1: create();
		}

	}
}
//---------------------------------------------------------------------//
bool isTypeCorrect()
{
	if (cin.get() == '\n')
		return true;
	else
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return false;
	}
}
int inputNum(int left_range, int right_range)
{
	int number;
	while (true)
	{
		cin >> number;
		if (isTypeCorrect() && (number >= left_range) && (number <= right_range))
		{
			return number;
		}
		else
		{
			cout << "\n\n\t������� ������������ �����(�)!";
			if ((number <= left_range) || (number >= right_range))
				cout << "\t ����� ����� ���� ������ �� " << left_range << " � �� " << right_range << " !";
			cout << "\n\t\t���������� ��� ���: ";
		}
	}
}
double insert()
{

	double l;
	{
		while (true)
		{
			cin >> l;
			if (cin.get() == '\n') {
				break;
			}
			else {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "������������ ���� ! ������� ������: \n";
			}

		}
	} return l;
}

void create()
{
	setlocale(LC_ALL, "rus");
	double a, b, c, D, x1, x2;
	cout << "b^2-4*a*c - ���������� ��������� " << endl;
	cout << "������� a: " << endl;
	a = insert();
	cout << "������� b: " << endl;
	b = insert();
	cout << "������� c: " << endl;
	c = insert();
	D = (b * b) - (4 * a * c);
	cout << "������������ �����: " << setprecision(4) << D << endl;
	if (D == 0) {
		x1 = -b / (2 * a);
		cout << "������: " << setw(10) << setfill('#') << setprecision(4) << x1 << endl;

	}
	if (D > 0) {
		x1 = (-b - sqrt(D)) / (2 * a);
		x2 = (-b + sqrt(D)) / (2 * a);
		cout << "����� ������� ���������: " << setw(5) << setfill('#') << setprecision(4) << x1 << setw(10) << setprecision(4) << x2 << endl;
	}
	if (D < 0) {
		cout << " ��� ������ " << endl;
	}
	system("pause");
}
