#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	const int len = 81;
	char word[len], line[len];

	cout << "Введите слово для поиска: "; cin >> word;

	ifstream fin( "text1.txt" );
	if ( !fin ) { cout << "Ошибка открытия файла." << endl; return 1; }

	fin.getline( line, len )
	
	while ( fin.getline( line, len ) ) {
		cout << line << endl
		if ( strstr( line, word ) ) { cout << "Присутствует!" << endl; return 0; }
	}

	cout << "Отсутствует!" << endl;

	return 0;
}