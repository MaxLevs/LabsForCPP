#include <iostream> // 1
using namespace std; // 2
int main() { // 3
	double fahr, cels; // 4
	setlocale(LC_ALL, "Russian");
	cout << endl << "������� ����������� �� ����������: "; // 5
	cin >> fahr; // 6
	cels = 5.0*(fahr - 32)/9; // 7
	cout << "�� ����������: " << fahr << ", �� �������: " << cels << endl; // 8
	system("pause");
	return 0; // 9
}