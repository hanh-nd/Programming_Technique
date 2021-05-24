#include<bits/stdc++.h>
using namespace std;

int n, s, killedEnemy, totalEnemy;

struct compare{
    bool operator() (pair<int, int> a, pair<int, int> b){
		return min(a.first, a.second) < min(b.first, b.second);
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, compare> Q;

int minEnemy(){
    while(!Q.empty() && s>0){
        pair<int, int> wall = Q.top(); 
		Q.pop();
        if(wall.first <= wall.second){
            killedEnemy += wall.first;
        } else {
            Q.push({wall.first - wall.second, wall.second});
            killedEnemy += wall.second;
        }
        s--;
    }
    return totalEnemy - killedEnemy;
}

int main(){
	cout << "Ngo Dang Hanh" << endl;
    cin >> n >> s;
    killedEnemy = 0;
    totalEnemy = 0;
    for(int i=0; i<n; i++){
        int a, k;
        cin >> a >> k;
        totalEnemy += a;
        Q.push({a, k});
    }
    cout << minEnemy();
    return 0;
}