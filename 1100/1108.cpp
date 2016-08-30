#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
typedef map<string, int> SIM;

int cnt, dfsn[2500], SN, sn[2500];
vector<int> adj[2500];
bool finished[2500];
stack<int> S;
vector<vector<int>> scc;

int dfs(int curr){
	dfsn[curr] = ++cnt;
	S.push(curr);
	int result = dfsn[curr];
	for(int next: adj[curr]){
		if(dfsn[next] == 0) result = min(result, dfs(next));
		else if(!finished[next]) result = min(result, dfsn[next]);
	}
	if(result == dfsn[curr]){
		vector<int> curscc;
		while(1){
			int n = S.top();
			S.pop();
			curscc.push_back(n);
			finished[n] = true;
			sn[n] = SN;
			if(n == curr) break;
		}
		scc.push_back(curscc);
		SN++;
	}
	return result;
}

int main(){
	int N, V = 0;
	cin >> N;
	SIM M;
	SIM::iterator finder;
	for(int i=0; i<N; i++){
		string site;
		int u, v, K;
		cin >> site >> K;
		finder = M.find(site);
		if(finder != M.end()) u = finder->second;
		else M[site] = u = V++;

		for(int j=0; j<K; j++){
			string link;
			cin >> link;
			finder = M.find(link);
			if(finder != M.end()) v = finder->second;
			else M[link] = v = V++;
			adj[v].push_back(u);
		}
	}
	for(int i=0; i<V; i++)
		if(dfsn[i] == 0) dfs(i);

	int sIndegree[2500] = {0}, sOrder[2500];
	vector<int> sAdj[2500];
	for(int i=0; i<V; i++){
		int Si = sn[i];
		for(int j: adj[i]){
			int Sj = sn[j];
			if(Si == Sj) continue;
			sAdj[Si].push_back(Sj);
			sIndegree[Sj]++;
		}
	}

	queue<int> Q;
	for(int i=0; i<SN; i++)
		if(sIndegree[i] == 0) Q.push(i);
	for(int i=0; i<SN; i++){
		int curr = Q.front();
		Q.pop();
		sOrder[i] = curr;
		for(int next: sAdj[curr])
			if(--sIndegree[next] == 0) Q.push(next);
	}

	long long score[2500] = {0};
	fill(score, score+V, 1);
	for(int k=0; k<SN; k++)
		for(int i: scc[sOrder[k]])
			for(int j: adj[i])
				if(sn[i] != sn[j]) score[j] += score[i];

	string dest;
	cin >> dest;
	finder = M.find(dest);
	if(finder != M.end()) cout << score[finder->second] << endl;
	else cout << 1 << endl;
}