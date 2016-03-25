#include <iostream>
#include <cmath>
#include <time.h>
#include <clocale>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	const int n = 10;
	int a[n] = { 1, 3, -5, 1, -2, 1, -1, 3, 8, 4 };
	int imax = 0, imin = 0, count = 0;

	cout << "Введите min и max значения для генерации массива: ";
	cin >> imin >> imax;
	//for(int i = 0; i < n; i++) a[i] = rand()+imin;
	for(int i = 0; i < n; i++) a[i] = imin + rand() % (imax - imin);

	imax = 0;
	imin = 0;

	cout << "Массив: ";
	cout << a[0] << "  ";
	for(int i = 1; i < n; i++){
		cout << a[i] << "  ";
		imin = (a[i]<a[imin])?i:imin;
		imax = (a[i]>a[imax])?i:imax;
	}

	cout << endl << endl;
	cout << "Максимальный эллемент  " << a[imax] << " с индексом " << imax << endl;
	cout << "Минимальный  эллемент " << a[imin] << " с индексом " << imin << endl;
	for(int i = min(imin, imax)+1; i < max(imin, imax); i++) if(a[i]>0) count++;
	cout << endl << "Кол-во положительных: " << count << endl << endl << endl;
}