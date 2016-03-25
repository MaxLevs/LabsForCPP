#include <iostream>
#include <clocale>

using namespace std;

int main(){
	setlocale(LC_ALL, "Russian");

	int const n = 10;
	int a[n] = { 1, 3, -5, 1, -2, 1, -1, 3, 8, 4 };
	int s = 0;
	int i = n-1;

	for(; i != (a[i]<0)?i:0; i--);
	for(; i < n; i++)s += a[i];


	return 0;
}