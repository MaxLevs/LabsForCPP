#include <iostream>
#include <cmath>
#include <locale>
using namespace std;
int main() {
	setlocale(0, "Russian");
	const int MaxIter = 500; // ����������� ���������� ���������� ��������
	double xb, xe, xd, x, eps;
	cout << "������� �������� � ��� ��������� � ��������:\n";
	cin >> xb >> xe >> xd >> eps;

	printf(" --------------------------- \n");
	printf("|     X    | Done |       S     | Count Iter |\n");
	printf(" --------------------------- \n");

	for (double x = xb; x <= xe; xb += xd) {
		bool done = true; // ������� ���������� ��������
		double ch = 1, s = 1; // ������ ���� ���� � ��������� �������� �����
		int i = 1;
		for (fabs(ch) > eps; i++;) {
			ch *= -((i + 1)*(i + 1)*x) / (i + 2); // ��������� ���� ����
			s += ch; // ���������� ����� ���� � �����
			if (i > MaxIter) {
				cout << "\n��� ����������!";
				done = false; break;
			}
		}
		printf("|%8.3lf |%6s |%9.2lf |%13d |\n", x, (done)?"true":"false", s, i);
	}

}