#include <cstdio>
#include <ncurses.h> //cd /usr/include/c++/4.8.4  Страдания...
#include <iostream>
#include <locale.h>

using namespace std;

int main() {
	setlocale(LC_CTYPE, "ru_RU.UTF8"); //Крокозябры off!

	initscr();
	printw("Нажмите одну из курсорных клавиш или BackSpase для выхода:\n");
	keypad(stdscr, true);	//Включаем режим чтения функциональных клавиш
	noecho();				//Выключаем отображение вводимых символов (нужно для getch())
	halfdelay(10);			//Устанавливаем ограничение по времени ожидания getch() в 10 сек
	int key = getch();
	do {
	switch (key) {
		case KEY_UP: printw("Стрелка вверх!\n"); break;
		case KEY_LEFT: printw("Стрелка влево!\n"); break;
		case KEY_RIGHT: printw("Стрелка вправо!\n"); break;
		case KEY_DOWN: printw("Стрелка вниз!\n"); break;
		default: printw("Это что-то не то!\n");
	}
	key = getch();
	} while (key != KEY_BACKSPACE);
	endwin();
	return 0;
}