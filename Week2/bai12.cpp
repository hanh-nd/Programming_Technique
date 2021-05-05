#include <iostream>
#include <map>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

int main(){
	//read maps
	ifstream input("intput.txt");
	vector<pair<int, int>> maps;
	while(!input.eof()){
		int key, value;
		input >> key >> value;
		maps.push_back(pair<int, int>(key, value));
	}
	input.close();
	
    //sort maps
    sort(maps.begin(), maps.end(), [](pair<int, int> &a, pair<int, int> &b){
        if(a.second != b.second){
            return a.second > b.second;
        }
        return a.first > b.first;
    });

    //print sorted map
    for(auto &it : maps){
        cout << it.first << " " << it.second << endl;
    }
    cout << "Ngo Dang Hanh" << endl;
    return 0;
}

