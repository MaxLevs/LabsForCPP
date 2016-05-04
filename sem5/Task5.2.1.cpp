#include <fstream>
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
int main() {
	const int len = 81;
	char word[len], line[len];

	cout << " Введите слово для поиска: "; cin >> word;
	int l_word = strlen( word );

	ifstream fin( "text1.txt" );
	if ( !fin ) { cout << "Ошибка открытия файла." << endl; return 1; }

	int count = 0;
	while ( fin.getline( line, len ) ) {
		cout << line << endl;
		char *p = line;

		while( p = strstr( p, word ) ) {
			char *c = p;
			p += l_word;

			if ( c != line )
				if ( !ispunct(*(c - 1) ) && !isspace(*(c - 1) ))
					continue;
				if ( ispunct(*p) || isspace(*p) || (*p == '\0'))
			count++;
		}
	}
	cout << "Количество вхождений слова: " << count << endl;
}