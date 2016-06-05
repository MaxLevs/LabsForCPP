#include <iostream>
#include <clocale>
#include <iomanip>

using namespace std;
	int main() {
	setlocale(LC_ALL, "Russian");
	const int nrow = 10, ncol = 20;
	int a[nrow][ncol];

		// Формируем исходный массив
		cout << "Введите элементы массива:" << endl;
		for ( int i = 0; i < nrow; i++ )
			for ( int j = 0; j < ncol; j++ ) cin >> a[i][j];

		// Выодим для проверки
		for ( int i = 0; i < nrow; i++ ) {
			for ( int j = 0; j < ncol; j++ ) cout << setw(4) << a[i][j] << " ";
		}

cout << endl;
cout << endl;
int n_pos_el;
float s = 0;
for ( int i = 0; i < nrow; i++ ) {
n_pos_el = 0;
for ( int j = 0; j < ncol; j++ ) {
s += a[i][j];
if ( a[i][j] > 0 ) n_pos_el++;
}
cout << " Строка: " << i << ", кол-во: " << n_pos_el << endl;
}
s /= nrow * ncol;
cout << "Среднее арифметическое: " << s << endl;

return 0;
}