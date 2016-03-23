#include <iostream>
#include <cmath>
using namespace std;
int main() {
	double a, b;
	setlocale(LC_ALL, "RUS");
	cout << "Введите начальные значения a и b через пробел: ";
	cin >> a >> b;
	cout << endl
		 << "Результат решения по первой формуле: " << pow(cos(a)-cos(b), 2.0)- pow(sin(a) - sin(b), 2.0) << endl
		 << "Результат решения по второй формуле: " << -4*pow(sin(0.5*(a-b)), 2.0)*cos(a+b) << endl;
	system("pause");
}