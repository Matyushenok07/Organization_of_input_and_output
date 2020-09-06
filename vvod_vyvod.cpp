/*Написать программу решения квадратного уравнения.
Установить ширину поля в 10 символов, точность - 4 цифры,пробелы заполнить символом*/
#include<iostream>
#include<math.h>
#include <iomanip> // данная библиотека содержит описание для манипуляторов

using namespace std;
void create();// ввод данных для вычисления квадратного уравнения 
double insert();// защита "От дурака"
bool isTypeCorrect();// проверка на соответствие введенных данных типу
int inputNum(int left_range, int right_range);// ввод номера пункта 
// --------------------------------------------------------------------//
void main() {
	setlocale(LC_ALL, "rus");
	create();
	while (true)
	{
		cout << " ----------Выбор пути------------ " << endl
			<< "1.Ввести ещё одни значения для дискриминанта  " << endl
			<< "0.Выйти из программы" << endl
			<< "Ваш выбор:";
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
			cout << "\n\n\tВведено некорректное число(№)!";
			if ((number <= left_range) || (number >= right_range))
				cout << "\t Число может быть только от " << left_range << " и до " << right_range << " !";
			cout << "\n\t\tПопробуйте ещё раз: ";
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
				cout << "Некорректный ввод ! Введите заново: \n";
			}

		}
	} return l;
}

void create()
{
	setlocale(LC_ALL, "rus");
	double a, b, c, D, x1, x2;
	cout << "b^2-4*a*c - квадратное уравнение " << endl;
	cout << "Введите a: " << endl;
	a = insert();
	cout << "Введите b: " << endl;
	b = insert();
	cout << "Введите c: " << endl;
	c = insert();
	D = (b * b) - (4 * a * c);
	cout << "Дискриминант равен: " << setprecision(4) << D << endl;
	if (D == 0) {
		x1 = -b / (2 * a);
		cout << "Корень: " << setw(10) << setfill('#') << setprecision(4) << x1 << endl;

	}
	if (D > 0) {
		x1 = (-b - sqrt(D)) / (2 * a);
		x2 = (-b + sqrt(D)) / (2 * a);
		cout << "Корни данного уравнения: " << setw(5) << setfill('#') << setprecision(4) << x1 << setw(10) << setprecision(4) << x2 << endl;
	}
	if (D < 0) {
		cout << " Нет корней " << endl;
	}
	system("pause");
}
