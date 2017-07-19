#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

int main(){
	int N, M = 0, ind[10000] = {0};
	unordered_map<string, int> S2N;
	vector<int> adj[10000];
	cin >> N;
	for(int i=0; i<N; i++){
		string A, op, B;
		cin >> A >> op >> B;
		int a = (S2N.find(A) == S2N.end() ? S2N[A] = M++ : S2N[A]);
		int b = (S2N.find(B) == S2N.end() ? S2N[B] = M++ : S2N[B]);
		if(op == ">"){
			adj[a].push_back(b);
			ind[b]++;
		}
		else{
			adj[b].push_back(a);
			ind[a]++;
		}
	}

	int vcnt = 0;
	queue<int> Q;
	for(int i=0; i<M; i++)
		if(ind[i] == 0) Q.push(i);
	while(!Q.empty()){
		int curr = Q.front(); Q.pop();
		vcnt++;
		for(int next: adj[curr])
			if(--ind[next] == 0) Q.push(next);
	}
	cout << (vcnt == M ? "possible" : "impossible") << endl;
}