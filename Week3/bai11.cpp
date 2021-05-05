#include <bits/stdc++.h>
using namespace std;
#define MAX 10000  

int n, r, c[MAX][MAX]; //# số địa điểm, số danh sách và ma trận chi phí
int cmin = INT_MAX; //# chi phí đi lại nhỏ nhất giữa hai thành phố khác nhau
int best = INT_MAX; //# tổng chi phí nhỏ nhất cần tìm, ban đầu đặt bằng giá trị vô cùng lớn INT_MAX = 2^31-1
int curr; //# tổng chi phí tới thời điểm hiện tại
int mark[MAX]; //# đánh dấu những thành phố đã đi
int x[MAX]; //# lưu giữ các thành phố đã đi
vector<int> destinationList, solutionList;
int first, last, numberOfDestination;

void input(){
    cin >> n >> r;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            cin >> c[i][j];
            if (c[i][j] > 0) cmin = min(cmin, c[i][j]);
        }
}

void solution(){
    if(c[x[numberOfDestination - 2]][last] == 0) return;
    best = min(best, curr + c[x[numberOfDestination-2]][last]);
}

void TRY(int k){
    for(int i=1; i<numberOfDestination-1; i++){
        if(!mark[destinationList[i]] && c[x[k - 1]][destinationList[i]]) {
            mark[destinationList[i]] = 1;
            curr += c[x[k - 1]][destinationList[i]];
            x[k] = destinationList[i];
            
            if(k == numberOfDestination - 2) {
            	solution();
		} else if (curr + cmin * (n - numberOfDestination + 3)) {
            		TRY(k + 1);
		}

            mark[destinationList[i]] = 0;
            curr -= c[x[k - 1]][destinationList[i]];
        }
    }
}

int main() { 
	cout << "Ngo Dang Hanh" << endl;
    string str;
    input(); 
	getline(cin,str);

    for (int i = 1; i <= r; ++i) {
        best = INT_MAX;
        curr = 0;
        getline(cin, str);

        while (!str.empty()) {
            stringstream convert(str.substr(0, str.find(" ")));
            int temp = 0;
            convert >> temp;
            destinationList.push_back(temp - 1);

            if (str.find(" ") > str.size()) {
                break;
            } else {
                str.erase(0, str.find(" ") + 1);
            }
        }

        first = destinationList[0];
        last = destinationList[destinationList.size() - 1];
        numberOfDestination = destinationList.size();
        x[0] = first; 
		x[numberOfDestination-1] = last;
		
        for(int i=0; i<n; i++) {
        	mark[i] = 0;
		}

        TRY(1);

        if(best == INT_MAX) {
        	solutionList.push_back(0);
		} else {
			solutionList.push_back(best);
		}
        destinationList.erase(destinationList.begin(), destinationList.end());
    }
    
    for (auto i = solutionList.begin(); i != solutionList.end(); ++i) {
    	cout << *i << endl;
	}
}
