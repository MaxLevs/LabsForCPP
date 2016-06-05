#include <cstdio>
#include <cstring>

using namespace std;


int main() {

	const int l_name = 30;

	struct Man {
		int birth_year;
		char name[l_name + 1];
		float pay;
	};

	const int l_dbase = 100;
	Man dbase[l_dbase];
	char name[l_name + 1];
	FILE *fin;

	if ( ( fin = fopen( "dbase.txt", "r" ) ) == NULL ) {puts( "Ошибка открытия файла\n" ); return 1; }

	int i = 0;
	while ( !feof ( fin ) ) {
		fgets( dbase[i].name, l_name, fin );
		fscanf( fin, "%i%f\n", &dbase[i].birth_year, &dbase[i].pay );
		i++;
		if ( i > l_dbase ) { puts( "Слишком длинный файл\n" ); return 1; }
	}

	int n_record = i, n_man = 0;
	float mean_pay = 0;

	while ( true ) {
		puts("Введите фамилию или нажмите Enter для окончания: "); gets( name );
		if ( strlen(name) == 0 ) break;
		bool not_found = true;
		for ( int i = 0; i < n_record; i++ ) {
			if ( strstr( dbase[i].name, name ))
				if ( dbase[i].name[strlen(name)] == ' ' ) {
					printf( "%30s%5i%10.2f\n", dbase[i].name, dbase[i].birth_year, dbase[i].pay );
					n_man++; mean_pay += dbase[i].pay;
					not_found = false;
				}
		}
		if ( not_found ) puts( "Такого сотрудника нет\n" );
	}
	
	if ( n_man > 0 ) printf( " Средний оклад: %10.2f\n", mean_pay / n_man );
}