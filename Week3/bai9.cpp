#include <bits/stdc++.h>
using namespace std;

int n, K1, K2;
int x[100];

void print_sol() {
	int count = 0;
	int maxWorkingDay = 0;
	int minWorkingDay = 99999;
	for (int i = 1; i <= n + 1; ++i) {
		if (x[i] == 0) {	
			if (count){
				minWorkingDay = min(minWorkingDay, count);
				maxWorkingDay = max(maxWorkingDay, count);
			}
			count = 0;
		} else count++;
	}
	
	if (K1 <= minWorkingDay && minWorkingDay <= K2 && K1 <= maxWorkingDay && maxWorkingDay <= K2) {
		for (int i = 1; i <= n; ++i) {
			cout << x[i];
		}
		cout << endl;
	}
}

void TRY(int k) {
	for (int i = 0; i <= 1; ++i) {
		x[k] = i;
		if (x[k - 1] + x[k] == 0) {
			continue;
		}
		
		if (k == n) {
			print_sol();
		}
		else TRY(k + 1); 		
	}
}

int main() {
	cout << "Ngo Dang Hanh" << endl;
	cin >> n >> K1 >> K2;
	x[0] = 1;
	TRY(1);	
	return 0;
}
