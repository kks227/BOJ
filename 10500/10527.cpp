#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main(){
	int N;
	cin >> N;
	map<string, int> M[2];
	for(int i=0; i<2; i++){
		for(int j=0; j<N; j++){
			string S;
			cin >> S;
			auto iter = M[i].find(S);
			if(iter != M[i].end()) iter->second++;
			else M[i][S] = 1;
		}
	}
	int result = 0;
	for(auto iter1: M[0]){
		auto iter2 = M[1].find(iter1.first);
		if(iter2 != M[1].end()) result += min(iter1.second, iter2->second);
	}
	cout << result << endl;
}