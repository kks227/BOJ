#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main(){
	int N;
	unordered_map<string, int> cnt;
	cin >> N;
	for(int i = 0; i < N; ++i){
		string S;
		cin >> S;
		cnt[S] = (cnt.find(S) != cnt.end() ? cnt[S] : 0) + 1;
	}
	for(int i = 0; i < N-1; ++i){
		string S;
		cin >> S;
		--cnt[S];
	}
	for(auto &p: cnt)
		if(p.second) cout << p.first << '\n';
}