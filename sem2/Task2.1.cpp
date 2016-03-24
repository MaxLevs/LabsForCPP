#include <iostream>
#include <clocale>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	float x, y;
	system("clear");
	cout <<"Введите значение аргумента: ";
	cin >> x;
	if (x<=-2) y=0;
	else if (x<-1) y=-x-2;
	else if (x<1) y=x;
	else if (x<2) y=-x+2;
	else y=0;
	cout << "При x, равном " << x << ", функция y(x)=" << y << "\n";
	system("echo; echo;");
	return 0;
}