#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
const int MAX = 50;

int main(){
	int N;
	unordered_set<string> S;
	cin >> N;
	for(int i = 0; i < N; ++i){
		string T;
		cin >> T;
		int K = T.size();
		bool flag = true;
		for(int i = 0; i < K; ++i){
			if(S.find(T) != S.end()){
				flag = false;
				break;
			}
			T = string(1, T.back()) + T;
			T.pop_back();
		}
		if(flag) S.insert(T);
	}
	cout << S.size() << '\n';
}