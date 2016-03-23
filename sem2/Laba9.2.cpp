#include <iostream>
#include <stdio.h>
#include <cmath>
#include <locale>
#include <fstream>
#include <string.h>


using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	const int MaxIter = 500; // максимально допустимое количество итераций
	double xb, xe, xd, eps; //
	ofstream fout;

	cout << "\n\nВведите диапазон и шаг аргумента; точность расчета:\n";
	cin >> xb >> xe >> xd >> eps;

	system("rm results.txt");
	fout.open("results.txt");
	fout.precision(10);

	fout << "-------------------------------------------\n";
	fout << "|            Входные данные               |\n";
	fout << "-------------------------------------------\n";
	fout << "X нач. = " << xb << "\n";
	fout << "X кон. = " << xe << "\n";
	fout << "dX = " << xd << "\n";
	fout << "Точн. = " << eps << "\n\n";


	printf("-------------------------------------------\n");
	printf("|    X   |  Done  |    S    |  Count Iter |\n");
	printf("-------------------------------------------\n");

	fout << "------------------------------------------------\n";
	fout << "|      X      |  Done  |    S    |  Count Iter |\n";
	fout << "------------------------------------------------\n";

	for (double x = xb; x <= xe; x += xd) {
		bool done = true; // признак достижения точности
		double c1 = 1, s = 1; // первый член ряда и начальное значение суммы
		int i = 1;
		for (; fabs(c1) > eps; i++) {
			c1 *= -((i + 1)*x)/(i*i); // очередной член ряда
			s += c1; // добавление члена ряда к сумме
			if (i == MaxIter) {
				done = false; break;
			}
		}
		printf("| %8.5lf |%6s| %9.2lf |%13d|\n", x, (done)?"true":"false", s, i);
		string dn = (done)?"true ":"false";
		string sn = (s>0)?s:(" " + s)
		fout << "|" << x << "|" << dn << "|" << sn << "|" << i << "|" << "\n";
	}

}