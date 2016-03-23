#include <iostream>
#include <cmath>
#include <locale>
using namespace std;
int main() {
	setlocale(0, "Russian");
	const int MaxIter = 500; // максимально допустимое количество итераций
	double xb, xe, xd, x, eps;
	cout << "Введите диапазон и шаг аргумента и точность:\n";
	cin >> xb >> xe >> xd >> eps;

	printf(" --------------------------- \n");
	printf("|     X    | Done |       S     | Count Iter |\n");
	printf(" --------------------------- \n");

	for (double x = xb; x <= xe; xb += xd) {
		bool done = true; // признак достижения точности
		double ch = 1, s = 1; // первый член ряда и начальное значение суммы
		int i = 1;
		for (fabs(ch) > eps; i++;) {
			ch *= -((i + 1)*(i + 1)*x) / (i + 2); // очередной член ряда
			s += ch; // добавление члена ряда к сумме
			if (i > MaxIter) {
				cout << "\nРяд расходится!";
				done = false; break;
			}
		}
		printf("|%8.3lf |%6s |%9.2lf |%13d |\n", x, (done)?"true":"false", s, i);
	}

}