#include <fstream>
#include <iostream>
#include <clocale>
#include <iomanip>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	ifstream fin( "./input.txt");
	if (!fin) { cout << " Файл input.txt не найден " << endl; return 1; }

	int nrow = 0, ncol = 0;
	fin >> nrow >> ncol;

	int **arr = new int *[nrow];	// Массив  исходный (указателей на целое)
	long *s = new long[nrow];		// Массив с суммами элементов строк

	cout << "Входной массив: " << endl;
	for (int i = 0; i < nrow; ++i){
		arr[i] = new int[ncol];	//Инициализируем массив указателей на целое
		s[i] = 0;					// Зануляем сумму эл. i-той строки
		for (int j = 0; j < ncol; ++j){
			fin >> arr[i][j];		//Заполняем очередной элемент
			s[i] += arr[i][j];		//В сумму его!
			cout << setw(4) << arr[i][j] << " ";
		}
		cout << "| " << s[i] << endl;
	}

	//Можно начинать сортировку!
	int *stackl = new int[nrow], *stackr = new int[nrow];
	int sp = 1; stackl[sp] = 0; stackr[sp] = nrow-1;
	int *buff;

	while(stackl[sp] < stackr[sp]){
		int left = stackl[sp];
		int right = stackr[sp];
		--sp;

		while(left < right){
			int i = left, j = right;
			float middle = s[(left+right)/2];

			while(i < j){
				while(s[i] < middle) ++i;
				while(middle < s[j]) --j;
				if ( i <= j ) {
					float temp = s[i]; s[i] = s[j]; s[j] = temp;
					buff = arr[i]; arr[i] = arr[j]; arr[j] = buff;
					i++; j--;
				}
			}

			if(i < right){
				++sp; stackl[sp] = i; stackr[sp] = right;
			}
			right = j;
		}
	}

	cout << "-------------------------------------" << endl << endl;
	cout << "Отсортированный:" << endl;
	for (int i = 0; i < nrow; ++i){
		for (int j = 0; j < ncol; ++j)
			cout << setw(4) << arr[i][j] << ' ';
		cout <<  endl;
	}
	cout << endl;
	return 0;

}