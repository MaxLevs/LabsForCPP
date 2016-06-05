#include <fstream>
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	ifstream fin( "text1.txt" );
	if ( !fin ) { cout << "Ошибка открытия файла." << endl; return 1; }

	long slu = 0;

	cout << "Кол-во слов: ";
	cin >> slu;

	fin.seekg( 0, ios::end );
	long len = fin.tellg();
	char *buf = new char [len + 1];
	fin.seekg( 0, ios::beg );
	fin.read( buf, len );

	buf[len] = '\0'; long n = 0, i = 0, sl = 0;
	while( buf[i] != '\0' ) {
		if (isspace(buf[i])) {
			sl++;
		}
		
		if (buf[i] == '?' || buf[i] == '.' || buf[i] == '!') {
			if (sl+1 == slu){
				for ( int j = n; j <= i; j++ ) cout << buf[j];
				cout << endl;
			}
			while (isspace(buf[i+1])) i++; //Считаем до начала след предложения.
			n = i+1; //Убираем единственный пробельный символ.
			sl = 0; //Зануление счетчика слов.
		}
		i++;
	}
	fin.close();
	cout << endl;
}