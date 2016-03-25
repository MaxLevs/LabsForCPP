#include <cstdio>
#include <ncurses.h> //cd /usr/include/c++/4.8.4
#include <iostream>

using namespace std;

int main() {
	initscr();
	printw("Нажмите одну из курсорных клавиш:\n");
	keypad(stdscr, true);	//Включаем режим чтения функциональных клавиш
	noecho();				//Выключаем отображение вводимых символов, нужно для getch()
	halfdelay(100);			//Устанавливаем ограничение по времени ожидания getch() в 10 сек
	int key = getch();
	switch (key) {
		case KEY_UP: printw("Стрелка вверх!\n"); break;
		case KEY_LEFT: printw("Стрелка влево!\n"); break;
		case KEY_RIGHT: printw("Стрелка вправо!\n"); break;
		case KEY_DOWN: printw("Стрелка вниз!\n"); break;
		default: printf("Это что-то не то!\n");
	}
	key = getch();
	endwin();
	return 0;
}