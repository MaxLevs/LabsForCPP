#include <cstdio>
#include <curses.h> //cd /usr/include/c++/4.8.4
#include <iostream>

using namespace std;

int main() {
	printf("\nНажмите одну из курсорных клавиш:\n");
	system("sleep 1s");
	initscr();
	keypad(stdscr, true);	//Включаем режим чтения функциональных клавиш
	noecho();				//Выключаем отображение вводимых символов, нужно для getch()
	halfdelay(100);			//Устанавливаем ограничение по времени ожидания getch() в 10 сек
	int key = getch();
	endwin();
	switch ( key ) {
		case KEY_UP: printf("Стрелка вверх\n"); break;
		case KEY_LEFT: printf("Стрелка влево\n"); break;
		case KEY_RIGHT: printf("Стрелка вправо\n"); break;
		case KEY_DOWN: printf("Стрелка вниз\n"); break;
		default: printf("Это что-то не то!\n");
	}
	return 0;
}