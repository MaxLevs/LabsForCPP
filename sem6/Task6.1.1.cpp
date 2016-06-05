#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <clocale>
#include <iomanip>

using namespace std;

int main() {
	//setlocale(LC_ALL, "ru_RU.UTF-8");


// Задаем длину буффера и его отдельных частей
	const int	l_name = 30, l_year = 5, l_pay = 10,
				l_buf = l_name + l_year + l_pay;


// Структура для хранения инфы о сотрудниках
	struct Man {
		int birth_year;
		char name[l_name + 1];
		float pay;
	};


// Начальные значения
	const int l_dbase = 100;	// Определяем кол-во записей
	Man dbase[l_dbase];			// Массив с сотрудниками
	char buf [l_buf + 1];		// Текущая запись (строка)
	char name[l_name + 1];		// Имя искомого сотрудника


// Читаем базу, проверяем на валидность
	ifstream fin( "dbase.txt" );
	if ( !fin ) { cout << " Ошибка открытия файла " << endl; return 1; }


//Заносим данные в массив, считая кол-во записей
	int i = 0;
	while (fin.getline ( buf, l_buf )) {
		if ( i >= l_dbase ) { cout << " Слишком длинный файл "; return 2; }	// Мониторим переполнение
		strncpy( dbase[i].name, buf, l_name );								// "Выдераем" имя из записи
		dbase[i].name[l_name] = '\0';										// "Оканчиваем" его
		dbase[i].birth_year = atoi(&buf[l_name]);							// Год рождения
		dbase[i].pay = atof(&buf[l_name + l_year]);							// Rich Bitch!
		//cout << dbase[i].name << " | " << dbase[i].birth_year << " | " << dbase[i].pay << endl; //Контрольный вывод (проверка кирилицы)
		i++;
	}


// Записываем число записей
// Готовимся к расчету среднего заработка
	int n_record = i, n_man = 0;
	float mean_pay = 0;

	while ( true ) {
		cout << "Введите фамилию или слово end: ";
		cin >> name;											// Искомая инфа
		
		if ( strcmp( name, "end" ) == 0 ) break;				// Даем возможность покинуть пределы программы
		
		bool not_found = true;
		for ( int i = 0; i < n_record; i++ ) {
			if ( strstr( dbase[i].name, name ) )
			if ( dbase[i].name[strlen( name )] == ' ' ) { 		//Проверка оконченности имени
				cout << dbase[i].name << dbase[i].birth_year << ' ' <<
				dbase[i].pay << endl;
				n_man++; mean_pay += dbase[i].pay;
				not_found = false;
			}
		}

		if ( not_found ) cout << " Такого сотрудника нет" << endl;
	}

	if ( n_man > 0 ) cout << " Средний оклад: " << mean_pay / n_man << endl;
}