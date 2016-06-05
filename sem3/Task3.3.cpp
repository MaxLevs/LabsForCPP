#include <iostream>
#include <clocale>

using namespace std;

int main(){
	int const n = 10;
	float arr[n] = { 1, 3, -5, 1, -2, 1, -1, 3, 8, 4 };
	int *stackl = new int[n], *stackr = new int[n];

/*	cout << "Введите элементы массива:";
	for (int i = 0; i < n-1, ++i) cin << arr[i];*/

	int sp = 1; stackl[sp] = 0; stackr[sp] = n-1;

	while(stackl[sp] < stackr[sp]){
		int left = stackl[sp];
		int right = stackr[sp];
		--sp;

		while(left < right){
			int i = left, j = right;
			float middle = arr[(left+right)/2];

			while(i < j){
				while(arr[i] < middle) ++i;
				while(middle < arr[j]) --j;
				if (i <= j) {
					float temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
					i++; j--;
				}
			}

			if(i < right){
				++sp; stackl[sp] = i; stackr[sp] = right;
			}
			right = j;
		}
	}

	for ( int i = 0; i < n; i++ ) cout << arr[i] << ' ';
	cout << endl;
	return 0;
}