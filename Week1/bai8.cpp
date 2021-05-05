#include <iostream>
using namespace std;

void allocate_mem(int ***matrix, int m, int n){
	*matrix = new int*[m];
	for(int i = 0; i < m; i++){
		(*matrix)[i] = new int[n];
	}
}

void getInput(int **matrix, int m, int n){
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; j++){
			cin >> *(*(matrix + i) + j);
		}
	}
}

void printOutput(int **matrix, int m, int n){
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; j++){
			cout << "mt[" << i << "][" << j << "] = ";
		}
	}
	
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; j++){
				cout << *(*(matrix + i) + j) << " ";
		}
		cout << endl;
	}

}

void calcSum(int **matrix, int m, int n){
	int sum = 0;
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; ++j){
			if(*(*(matrix + i) + j) % 2 == 0){
				sum += *(*(matrix + i) + j);
			}
		}
	}
	cout << "The sum of all even elements is " << sum;
}

void freemem(int **matrix, int m, int n){
	for(int i = 0; i < n; ++i){
		delete(*(matrix + i));
	}
	delete(matrix);
}

int main(){
	int m, n;
	int **matrix;
	
	cout << "Enter m, n = ";
	cin >> m >> n;
	
	allocate_mem(&matrix, m, n);
	getInput(matrix, m, n);
	printOutput(matrix, m, n);
	calcSum(matrix, m, n);
	freemem(matrix, m, n);
	return 0;
}




