#include <iostream>
using namespace std;

int main(){
	int size;
	cout << "Enter the number of elements: ";
	cin >> size;
	int arr[size];
	cout << "The input array is: " << endl;
	for(int i = 0; i < size; i++){
		cin >> *(arr + i);
	}

	for(int i = 0; i < size; i++){
		cout << *(arr + i) << " ";
	}
	
	for(int i = 0; i < size; i++){
		for(int j = i; j < size; j++){
			if(*(arr + i) > *(arr + j)){
				int temp = *(arr + i);
				*(arr + i) = *(arr + j);
				*(arr + j) = temp;
			}
		}
	}
	cout << "\n" << "The sorted array is: " << endl;
	for(int i = 0; i < size; i++){
		cout << *(arr + i) << " ";
	}
	return 0;
}




