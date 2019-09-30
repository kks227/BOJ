#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int MAX = 1000;

int N, M, A[MAX], B[MAX];
bool visited[MAX];
vector<int> adj[MAX];

bool dfs(int a){
	visited[a] = true;
	for(int b: adj[a]){
		if(B[b] == -1 || !visited[B[b]] && dfs(B[b])){
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}

int main(){
	cin >> N >> M;
	unordered_map<string, int> S2I;
	for(int i = 0; i < M; ++i){
		string name;
		cin >> name;
		S2I[name] = i;
	}
	for(int i = 0; i < N; ++i){
		int K;
		cin >> K;
		for(int j = 0; j < K; ++j){
			string name;
			cin >> name;
			adj[i].push_back(S2I[name]);
		}
	}
	int result = 0;
	fill(A, A+N, -1);
	fill(B, B+M, -1);
	for(int i = 0; i < N; ++i){
		fill(visited, visited+N, false);
		if(dfs(i)) ++result;
	}
	if(result == N) cout << "YES\n";
	else cout << "NO\n" << result << "\n";
}