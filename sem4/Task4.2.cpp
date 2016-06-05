#include <iostream>
#include <iomanip>
using namespace std;
int main() {
const int nrow = 5, ncol = 5;
int a[nrow][ncol];
bool flag = false;

cout << "Введите элементы массива:" << endl;
for ( int i = 0; i < nrow; i++ )
	for ( int j = 0; j < ncol; j++ ) cin >> a[i][j];

for ( int i = 0; i < nrow; i++ ) {
	for ( int j = 0; j < ncol; j++ ) cout << setw(4) << a[i][j] << " ";
}
cout << endl;

int i = 0;
for (i = 0; (i < nrow)&&(!flag); ++i) {
	flag = true;
	for (int j = 0; j < ncol; ++j) if (a[i][j] <= 0) flag = false;
}

if (flag) 
	cout << "Номер строки: " << i << endl;
else
	cout << "Не найдено!" << endl;


return 0;
}