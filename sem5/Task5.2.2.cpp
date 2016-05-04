#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	const int len = 81;
	char word[len], line[len];
	char delims[] = ",.!? /<>|)(*:;\"";

	cout << "Введите слово для поиска: "; cin >> word;

	ifstream fin( "text1.txt" );
	if ( !fin ) { cout << "Ошибка открытия файла." << endl; return 1; }

	int count = 0;
	while ( fin.getline( line, len ) ) {
		char *token = strtok( line, delims );
		while( token != NULL ) {
			if ( !strcmp ( token, word ) )count++;
			token = strtok( NULL, delims );
		}
	}
	cout << "Количество вхождений слова: " << count << endl;
}