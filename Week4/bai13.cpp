#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000000;
string str;
int arr[MAX];
int n, sum = 0, cnt = 0;

void input() {
	cin >> str;
	n = str.length();
	
	for (int i = 0; i < n; ++i) {
		if (str[i] == '0') {
			arr[i] = -1;
		} else {
			arr[i] = 1;
		}
	}
}

void countSubstring(int arr[], int n){
	map<int, int> mp;
  	for (int i = 0; i < n; ++i) {
        sum += arr[i];
        if (sum == 0)
            cnt++;
        if (mp[sum])
            cnt += mp[sum];
        if(!mp[sum])
            mp[sum] = 1;
        else
            mp[sum]++;
    }
}

int main(){
	cout << "Ngo Dang Hanh" << endl;
    input();
    countSubstring(arr, n);
    cout << cnt;
    return 0;
}