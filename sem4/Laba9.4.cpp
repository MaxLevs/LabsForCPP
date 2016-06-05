#include <fstream>
#include <iostream>
#include <clocale>
#include <iomanip>
#include <math.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	ifstream fin( "./input.txt");
	if (!fin) { cout << " Файл input.txt не найден " << endl; return 1; }

	const int nr = 10, nc = 10;
	int (*arr)[nr] = new int [nr][nc];
	float (*sth)[nr] = new float [nr][nc];
	float s = 0;


	cout << "Входная матрица: " << endl;
	for (int i = 0; i < nr; ++i){
		for (int j = 0; j < nc; ++j){
			fin  >> arr[i][j];						//Заполняем очередной элемент
			cout << setw(4) << arr[i][j] << " ";	//Открой свои секреты
		}
		cout << endl;
	}


	int n = 0;
	for (int i = 0; i < nr; ++i){
		for (int j = 0; j < nc; ++j){
			n = 0;
			for (int k = i-1; k <= i+1; ++k) for (int l = j-1; l <= j+1; ++l)
					if ((k >= 0) && (k < nr) && (l >= 0) && (l < nc) && (k != i || l != j)){
						sth[i][j] += arr[k][l];
						n++;
					}
			n = (n == 0) ? 1 : n;
			sth[i][j] /= n;
			if (i>j) s += fabs(sth[i][j]);
		}
	}





	cout << "-------------------------------------" << endl << endl;
	cout << "Сглаженная:" << endl;
	for (int i = 0; i < nr; ++i){
		for (int j = 0; j < nc; ++j)
			cout << setw(10) << sth[i][j] << ' ';
		cout <<  endl;
	}
	cout << "Искомая сумма: " << s << endl;
	return 0;

}