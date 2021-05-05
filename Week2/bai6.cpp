#include <iostream>
using namespace std;

void print(int n){
    cout << "n=" << n << endl;
}
int mul3plus1(int n){
    return n * 3  + 1;
}
int div2(int n){
    return n/2;
}
void simulate(int n, int (*odd)(int), int (*even)(int), void (*output)(int)){
    (*output)(n);
    if(n == 1) return;
    if(n % 2 == 0){
        n = (*even) (n);
    } else {
        n = (*odd) (n);
    }
    simulate(n, odd, even, output);
}
int main(){
    int (*odd)(int) = NULL;
    int (*even)(int) = NULL;
    odd = mul3plus1;
    even = div2;
    int n;
    cin >> n;
    simulate(n, odd, even, print);
    cout << "Ngo Dang Hanh";
    return 0;
}


