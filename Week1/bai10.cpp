#include <iostream>
using namespace std;
int **temp;

void allocate_mem(int ***mt, int n){
	*mt = new int*[n];
	for(int i = 0; i < n; ++i){
		(*mt)[i] = new int[n];
	}	
}

void getInput(int **mt, int n){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cin >> *(*(mt + i) +j);
		}
	}
}

void printOutput(int **mt, int n){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cout << *(*(mt + i) + j) << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void calcSum(int **mt1, int **mt2, int n){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			*(*(temp + i) + j) = *(*(mt1 + i) + j) + *(*(mt2 + i) + j);
		}
	}
}

void calcMultiply(int **mt1, int **mt2, int n){
	for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            *(*(temp + i) + j) = 0;
            for(int k = 0; k < n; k++)
                *(*(temp + i) + j) += (*(*(mt1 + i) + k) * *(*(mt2 + k) + j));
        }
    }
}

void free_mem(int **mt, int n){
	for(int i = 0; i < n; i++){
		delete(*(mt + i));
	}
	delete(mt);
}

int main(){
	int n, **mt1, **mt2;
    cout<<"Enter n: "; 
	cin>>n;
	
    allocate_mem(&mt1, n);
    cout<<"Enter Matrix 1" << endl; 
	getInput(mt1, n);
	
    allocate_mem(&mt2, n);
    cout<<"Enter Matrix 2" << endl;
	getInput(mt2,n);
	
    allocate_mem(&temp, n);

    calcSum(mt1, mt2, n);
    cout<<"Sum: " << endl;
    printOutput(temp, n);
    calcMultiply(mt1, mt2, n);
    cout<<"Multiply: " << endl;
    printOutput(temp, n);

    free_mem(mt1, n);
    free_mem(mt2, n);
    free_mem(temp, n);
	return 0;
}




