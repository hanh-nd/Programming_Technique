#include <iostream>

using namespace std;

void print_sol(int n, int h, int* x) {
	int count = 0;
	for (int i = 0; i < n; ++i) {
		if (x[i] == 1) {
			count++;
		}
	}
	if (count == h) {
		for (int i = 0; i < n; ++i) {
			cout << x[i];
		}
		cout << endl;
	}
}

void TRY(int k, int n, int h, int *x) {
	for (int i = 0; i <= 1; ++i) {
		x[k] = i;
		if (k == n - 1) {
			print_sol(n, h, x);
		} else {
			TRY(k + 1, n , h, x);
		}		
	} 
}

int main() {
	int t, n[100], h[100], x[100][100];
	cin >> t ;
	for (int i = 0; i < t; ++i) {
		cin >> n[i] >> h[i];
	}
	for (int i = 0; i < t; ++i) {
		cout << endl;
		TRY(0, n[i], h[i], x[i]);
	}
	return 0;
}
