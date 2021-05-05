#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int main() {
    int val1, val2;
    cin >> val1 >> val2;
    vector <vector<int>> a = {
        {1, 3, 7},
        {2, 3, 4, val1},
        {9, 8, 15},
        {10, val2},
    };
    for (const auto v : a){
        sort(a.begin(), a.end(), [](vector<int> a, vector<int> b){
            int sumA = 0, sumB = 0;
            for(auto x : a){
                sumA += x;
        }
            for(auto y : b){
                sumB += y;
            }
            return sumA > sumB; 
        });
    }
    for (const auto &v : a) {
        for (int it : v) {
            cout << it << ' ';
        }
        cout << endl;
    }
    cout << "Ngo Dang Hanh";
    return 0;
}


