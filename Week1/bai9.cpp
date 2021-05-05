#include <iostream>
using namespace std;

void printSubarray(int *a, int size){
	for(int i = 0; i < size; ++i){
		for(int j = i; j < size; ++j){
			for(int k = i; k <= j; ++k){
				cout << *(a+k) << " ";
			}
			cout << endl;
		}		
	}
}

int main(){
	int size;
	cout << "Enter size: ";
	cin >> size;
	int *a = new int[size];
	cout << "Enter array: ";
	for(int i = 0; i < size; ++i){
		cin >> *(a+i);
	}
	printSubarray(a, size);
	delete[] a;
	return 0;
}

