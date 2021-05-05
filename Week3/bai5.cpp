#include <iostream>
using namespace std;

int binom(int n, int k) {
    if (k > n) return 0;
    if (k == 0) return 1;
    return binom(n-1, k) + binom(n-1, k-1);
}

long A[10000][10000];
int binom2(int n, int k){
	if (k > n) return 0;
	if (k == 0) {
		return 1;
	}
	A[n][k] = A[n - 1][k] + A[n - 1][k - 1];
	return A[n][k];
}

int main() {
	cout << "Ngo Dang Hanh" << endl;
    int m;
    cin >> m;
    for (int n = 1; n <= m; ++n){
        for (int k = 0; k <= n; ++k)
            printf("%d ", binom(n, k));
        printf("\n");
    }
    
    for (int i = 1; i <= m; ++i) {
    	A[i][0] = 1;
    	A[0][i] = 1;
	}
    
    for (int n = 1; n <= m; ++n){
        for (int k = 0; k <= n; ++k)
            printf("%d ", binom2(n, k));
        printf("\n");
    }

    return 0;
}