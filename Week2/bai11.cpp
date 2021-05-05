#include <iostream>

using namespace std;

void scanPoly(int *a, int n){
    for(int i = 0; i <= n; i++){
        cin >> a[i];
    }
}

void printSol(int *a, int n){
    int xor_a = a[0] ^ a[1];
    for(int i = 2; i < n; ++i){
        xor_a ^= a[i];
    }
    cout << xor_a << endl;
}

void multiplyPoly(){
    //get polynomials
    int *a, n;
    cin >> n;
    a = new int[n+1];
    scanPoly(a, n);

    int *b, m;
    cin >> m;
    b = new int[m+1];
    scanPoly(b, m);

    //calc muliply
    int *c, p = m + n + 1;
    c = new int[p];
    for(int i = 0; i < p; ++i){
        c[i] = 0;
    }
    for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= m; ++j){
            c[i+j] += a[i] * b[j];
        }
    }

    printSol(c, p);
    delete[] a;
    delete[] b;
}

int main(){
    multiplyPoly();
    cout << "Ngo Dang Hanh" << endl;
    return 0;
}