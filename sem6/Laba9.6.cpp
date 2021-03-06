#include <iostream>
#include <clocale>
#include <cstring>


using namespace std;

int main(){
	setlocale(LC_ALL, "Russian");
	
	const int n = 40, m = 8;
	struct TRAIN{
		unsigned short numb;
		char  time;
		char  ePoint[n];
	} arr[8];
	
	cout << "Введите информацию о 8 маршрутах (Номер, названия начальной и конечной остановки):" << endl;
	
	for(int i = 0; i < m; ++i){
		cout << i + 1 << ".1) ";
		cin >> arr[i].sPoint;
		
		cout << i + 1 << ".2) ";	
		cin >> arr[i].ePoint;

		cout << i + 1 << ".3) ";  
		cin >> arr[i].numb;	
	};

	int min;	
	for(int i = 0; i < m-1; ++i){
		min = i;
		for(int j = i; j < m; ++j)
			if(arr[j].numb < arr[min].numb) min = j;
		TRAIN buff = arr[i];
		arr[i] = arr[min];
		arr[min] = buff;
		
		cout << arr[i].numb << endl;
	}
	        cout << arr[m].numb << endl;
	

	return 0;
}
