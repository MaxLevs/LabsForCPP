#include <iostream>
#include <clocale>
#include <time.h>

using namespace std;

int main(){
	setlocale(LC_ALL, "Russian");

	int const n = 10;
	int a[n];
	int imax = 0, imin = 0, s = 0, i = n-1, j = -1;


	cout << "Введите min и max значения для генерации массива: ";
	cin >> imin >> imax;
	cout << "Массив: ";
	srand(time(NULL));
	for(int j = 0; j < n; j++){ a[j] = imin + rand() % (imax - imin); cout << a[j] << "  ";}          //Отладка
	cout << endl << endl;
	
	for(; j < i; i--) if(a[i] < 0) j = i+1; //С учетом перескока за последнее отрицательное

	if (j == -1) {
		cout << "Массив не содержит отрецательных эллементов!" << endl << endl;
		return 1;
	}

	for(; j < n; j++) s += a[j];        // +Отладка

	cout << "Значение суммы: " << s << endl << endl;
	return 0;
}