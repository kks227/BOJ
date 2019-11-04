#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int MAX = 200001;

int main(){
	int N, M = 1;
	cin >> N;
	unordered_map<string, int> H;
	H["Baba"] = 0;
	vector<string> S(1, "Baba");
	vector<int> adj[MAX];
	for(int i = 0; i < N; ++i){
		string A, is, B;
		cin >> A >> is >> B;
		if(H.find(A) == H.end()){
			H[A] = M++;
			S.push_back(A);
		}
		if(H.find(B) == H.end()){
			H[B] = M++;
			S.push_back(B);
		}
		int u = H[A], v = H[B];
		adj[u].push_back(v);
	}

	bool visited[MAX] = {true,};
	queue<int> Q;
	Q.push(0);
	vector<string> result;
	while(!Q.empty()){
		int curr = Q.front(); Q.pop();
		for(int next: adj[curr]){
			if(!visited[next]){
				visited[next] = true;
				result.push_back(S[next]);
				Q.push(next);
			}
		}
	}
	sort(result.begin(), result.end());
	for(auto &s: result)
		cout << s << '\n';
}