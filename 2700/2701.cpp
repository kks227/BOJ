#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main(){
	vector<int> adj[7] = {
		{2, 5},
		{2, 6},
		{0, 1, 3},
		{2, 4},
		{3, 5},
		{0, 4, 6},
		{1, 5}
	};
	string E(" ABCDEF");
	queue<string> Q;
	Q.push(E);
	unordered_map<string, string> prev;
	unordered_map<string, int> dist;
	prev[E] = "";
	for(int i=0; !Q.empty(); i++){
		int qSize = Q.size();
		for(int j=0; j<qSize; j++){
			string C = Q.front(); Q.pop();
			dist[C] = i;

			int pos = 0;
			for(int k=1; k<7; k++)
				if(C[k] == ' ') pos = k;
			string N = C;
			for(int npos: adj[pos]){
				swap(N[pos], N[npos]);
				if(prev.find(N) == prev.end()){
					prev[N] = C;
					Q.push(N);
				}
				swap(N[pos], N[npos]);
			}
		}
	}

	int T;
	cin >> T;
	for(int t=0; t<T; t++){
		string S;
		cin >> S;
		S.insert(0, " ");
		if(prev.find(S) == prev.end()) cout << -1 << endl;
		else{
			cout << dist[S] << ' ';
			while(S != E){
				for(int i=0; i<7; i++)
					if(S[i] == ' ') cout << prev[S][i];
				S = prev[S];
			}
			cout << endl;
		}
	}
}