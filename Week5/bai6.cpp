#include <bits/stdc++.h>
using namespace std;

char cal(double a){
    if (a < 4) return 'F';
    if (a < 5.5) return 'D';
    if (a < 7) return 'C';
    if (a < 8.5) return 'B';
    return 'A';
}

int main(){
    int n;
    cin >> n;
    int A = 0, B = 0, C = 0, D = 0, F = 0;
    while(n--){
        int a;
        cin >> a;
        char calres = cal(a);

        if (calres == 'A') ++A;
        if (calres == 'B') ++B;
        if (calres == 'C') ++C;
        if (calres == 'D') ++D;
        if (calres == 'F') ++F;
    }
    cout << A << " " << B << " " << C << " " << D << " " << F;
}