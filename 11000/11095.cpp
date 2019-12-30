#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int MAX = 32;

int main(){
	int N = 0, M;
	unordered_map<string, int> H;
	vector<int> adj[MAX];
	string name[MAX], st;
	cin >> M;
	cin.ignore(512, '\n');
	for(int i = 0; i < M; ++i){
		string line;
		getline(cin, line);
		stringstream ss(line);
		ss >> st;
		if(H.find(st) == H.end()){
			name[N] = st;
			H[st] = N++;
		}
		int u = H[st];
		while(ss >> st){
			if(H.find(st) == H.end()){
				name[N] = st;
				H[st] = N++;
			}
			int v = H[st];
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
	}

	cin >> st;
	if(H.find(st) == H.end()){
		name[N] = st;
		H[st] = N++;
	}
	int s = H[st];
	cin >> st;
	if(H.find(st) == H.end()){
		name[N] = st;
		H[st] = N++;
	}
	int e = H[st];
	queue<int> Q;
	int prev[MAX];
	fill(prev, prev + N, -1);
	Q.push(s);
	prev[s] = s;
	while(!Q.empty()){
		int curr = Q.front(); Q.pop();
		for(int next: adj[curr]){
			if(prev[next] == -1){
				prev[next] = curr;
				Q.push(next);
			}
		}
	}
	if(prev[e] == -1) cout << "no route found\n";
	else{
		vector<int> result;
		for(int i = e; i != s; i = prev[i])
			result.push_back(i);
		result.push_back(s);
		for(int i = result.size()-1; i >= 0; --i)
			cout << name[result[i]] << ' ';
	}
}