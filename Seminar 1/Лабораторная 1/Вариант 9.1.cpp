#include <iostream>
#include <cmath>
using namespace std;
int main() {
	double a, b;
	setlocale(LC_ALL, "RUS");
	cout << "������� ��������� �������� a � b ����� ������: ";
	cin >> a >> b;
	cout << endl
		 << "��������� ������� �� ������ �������: " << pow(cos(a)-cos(b), 2.0)- pow(sin(a) - sin(b), 2.0) << endl
		 << "��������� ������� �� ������ �������: " << -4*pow(sin(0.5*(a-b)), 2.0)*cos(a+b) << endl;
	system("pause");
}