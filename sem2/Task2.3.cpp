#include <cstdio>
#include <curses.h> //cd /usr/include/c++/4.8.4
#include <iostream>

using namespace std;

int main() {
	initscr();
	printf("\nНажмите одну из курсорных клавиш:\n");
	cout << KEY_UP << "\n";
	int key;
	timeout(-1);
	key = getch();
	endwin();
	switch ( key ) {
		case KEY_UP: printf("Стрелка вверх\n"); break;
		case 97: printf("A\n"); break;
		case 115: printf("S\n"); break;
		case 100: printf("D\n"); break;
		case 27: printf("А ведь я ничего не говорил про стрелки)\n"); break;
	default: printf("Это что-то не то!\n");
	}
	return 0;
}