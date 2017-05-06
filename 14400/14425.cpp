#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main(){
	int N, M, result = 0;
	cin >> N >> M;
	unordered_set<string> S;
	for(int i=0; i<N; i++){
		string W;
		cin >> W;
		S.insert(W);
	}
	for(int i=0; i<M; i++){
		string W;
		cin >> W;
		if(S.find(W) != S.end()) result++;
	}
	cout << result << endl;
}