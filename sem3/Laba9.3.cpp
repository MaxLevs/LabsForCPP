#include <iostream>
#include <clocale>

using namespace std;

int main(){
	setlocale(LC_ALL, "Russian");
	int const n = 10;
	int a[n] = { 0, 3, -50, 0, -2, 0, -1, 3, 8, 4 };

/*	cout << "Введите элементы массива:";
	for (int i = 0; i < n; ++i) cin >> a[i];
*/


	cout << "Задание №1" << endl;

	int mi = 0;
	for (int i = 1; i < n; ++i) if (abs(a[i]) > abs(a[mi])) mi = i;
	cout << "Эллемент под номером " << mi+1 << " максимален по модулю и имеет значение " << a[mi] << endl << endl;





	cout << "Задание №2" << endl;

	int i; mi = 0;
	for (i = 0; a[i] <= 0; ++i); ++i; //Листаем до первого положительного!
		cout << i << endl;
	for (; a[i] <= 0; ++i) mi += a[i]; //Ссумируем всё до следующего положительного!
	cout << "Сумма эллементов между первыйми положительными равна " << mi << endl << endl;




 
	cout << "Задание №3" << endl;

	int di = 0; //Смещение элментов = кол-ву отрицательныых (на сколько смещать неотрицательные)

	for (int i = 0; i < n; ++i) if (a[i] == 0) di++; else a[i - di] = a[i]; //Смещаем элементы к началу на кол-во встретившихся нулевых
	for (int i = n - di; i < n; ++i) a[i] = 0; //Зануляем ненужные (Последние).

	cout << "Преобразованный массив: ";
	for (int i = 0; i < n; ++i) cout << a[i] << " ";
	cout << endl;

	return 0;
}