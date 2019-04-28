#include <iostream>
#include <string>
#include <set>
#include <unordered_map>
using namespace std;

int main(){
	int N, Q;
	unordered_map<string, int> G2N;
	unordered_map<string, int> M2G;
	set<string> team[100];
	string gName[100];
	cin >> N >> Q;
	for(int i = 0; i < N; ++i){
		int k;
		cin >> gName[i] >> k;
		G2N[gName[i]] = i;
		for(int j = 0; j < k; ++j){
			string s;
			cin >> s;
			M2G[s] = i;
			team[i].insert(s);
		}
	}
	for(int i = 0; i < Q; ++i){
		int o;
		string s;
		cin >> s >> o;
		if(o == 0){
			for(string m: team[G2N[s]])
				cout << m << '\n';
		}
		else cout << gName[M2G[s]] << '\n';
	}
}