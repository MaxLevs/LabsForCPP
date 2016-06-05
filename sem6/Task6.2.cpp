#include <cstdio>
#include <cstring>

using namespace std;

int main() {
	
// Длина имени
	const l_name = 30;

// Структура под хранение данных
	stract Worker {
		char name[l_name + 1];
		int byear;
		float pay;
	}

	const l_base = 100;
	Worker db[l_base];
	char name[l_name + 1];
	FILE *fin;


// Открываем базу
	if((fin = fopen("dbase.txt", "r")) == NULL){
		puts("Возникла ошибка при открытии файла базы.");
		return 1;
	}


// Чтение записей базы; формирование массива структур 
	int i = 0;
	while (!feof(fin)) {
		fgets(db[i].name, l_name, fin);
		fscanf(fin, "%i%f\n", &db[i].byear, &db[i].pay);
		i++;
		if (i > l_base) {
			puts ("Слишком много записей!");
			return 2;
		}
	}



	



	return 0;
}