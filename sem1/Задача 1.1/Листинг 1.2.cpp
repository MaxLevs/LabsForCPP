#include <cstdio> // 1
#include <clocale> // 2
using namespace std; // 3
int main() { // 4
	setlocale(LC_ALL, "Russian"); // 5
	double fahr, cels; // 6
	printf("\n ������� ����������� �� ����������\n"); // 7
	scanf_s("%lf", &fahr); // 8
	cels = 5.0/9 * (fahr-32); // 9
	printf(" �� ����������: %6.2lf, �� ������� : %6.2lf\n", fahr, cels); // 10
	scanf_s("%lf", &fahr); // 8
}
