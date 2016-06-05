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
	// int a[n] = { 15, 22, -1, 16, -61, 32, 42, -11, 0, 5};
	// int a[n] = { -1, 23, -12, 1, 6, -8, 4, -6, 2, 2 };
	/*cout << "Введите min и max значения для генерации массива: ";
	cin >> imin >> imax;
	for(int i = 0; i < n; ++i) a[i] = imin + rand() % (imax - imin);*/

	int imax = 0, imin = 0, count = 0;



//Вывод масива и поиск Макс и Мин.
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

	//Собака. Я знаю. Но не хотел тратить лишнюю память на еще одну переменную.. Каюсь.
	count = imax; imax = max(imin, imax); imin = min(count, imin); count = 0;
	for(int i = imin+1; i < imax; ++i) if(a[i]>0) count++;
	cout << endl << "Кол-во положительных: " << count << endl << endl << endl;
	
	return 0;
}