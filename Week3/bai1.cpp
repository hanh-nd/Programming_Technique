#include <iostream>

using namespace std;

long L[10000];

int lucas(int n) {
	if (L[n] > 0) {
		return L[n];
	} 
	else if (n == 1) {
		L[n] = 1;
	}
	else if (n == 2) {
		L[n] = 2;
	}
	else {
		L[n] = lucas(n - 1) + lucas(n - 2);
	}
	return L[n];
	
}

int main() {
	cout << "Ngo Dang Hanh" << endl;
	int n;
	cin >> n;
	cout << lucas(n);
	return 0;
}