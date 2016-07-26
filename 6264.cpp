#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
typedef map<string, int> MapSI;

int cnt, dfsn[100], SN, sn[100];
vector<int> adj[100];
bool finished[100];
stack<int> S;
vector<vector<int>> scc;

int GetSCCsByDFS(int curr){
	dfsn[curr] = ++cnt;
	S.push(curr);
	int result = dfsn[curr];
	for(int next: adj[curr]){
		if(dfsn[next] == 0) result = min(result, GetSCCsByDFS(next));
		else if(!finished[next]) result = min(result, dfsn[next]);
	}
	if(result >= dfsn[curr]){
		vector<int> newScc;
		while(1){
			int t = S.top();
			S.pop();
			finished[t] = true;
			sn[t] = SN;
			newScc.push_back(t);
			if(t == curr) break;
		}
		scc.push_back(newScc);
		SN++;
	}
	return result;
}



int main(){
	while(1){
		int N;
		cin >> N;
		if(N == 0) break;

		for(int i=0; i<100; i++)
			adj[i].clear();
		string word[100];
		MapSI wordNum;
		vector<vector<string>> input;
		cin.ignore(256, '\n');
		for(int i=0; i<N; i++){
			string line;
			getline(cin, line);
			stringstream ss(line);
			ss >> word[i];
			wordNum[word[i]] = i;

			vector<string> dict;
			while(!ss.eof()){
				string def;
				ss >> def;
				dict.push_back(def);
			}
			input.push_back(dict);
		}
		for(int i=0; i<N; i++)
			for(string& s: input[i])
				adj[wordNum[s]].push_back(i);

		SN = cnt = 0;
		fill(dfsn, dfsn+N, 0);
		fill(sn, sn+N, 0);
		fill(finished, finished+N, 0);
		scc.clear();
		for(int i=0; i<N; i++)
			if(dfsn[i] == 0) GetSCCsByDFS(i);

		vector<int> sAdj[100], sPrecedessor[100];
		int sIndegree[100] = {0};
		for(int i=0; i<N; i++)
			for(int j: adj[i])
				if(sn[i] != sn[j]){
					sAdj[sn[i]].push_back(sn[j]);
					sPrecedessor[sn[j]].push_back(sn[i]);
					sIndegree[sn[j]]++;
				}
		queue<int> Q;
		for(int i=0; i<SN; i++)
			if(sIndegree[i] == 0) Q.push(i);

		vector<int> trace;
		bool need[100] = {0};
		while(!Q.empty()){
			int curr = Q.front();
			Q.pop();
			trace.push_back(curr);
			if(scc[curr].size() > 1) need[curr] = true;
			for(int next: sAdj[curr])
				if(--sIndegree[next] == 0) Q.push(next);
		}

		vector<string> result;
		for(int i=SN-1; i>=0; i--){
			int curr = trace[i];
			if(need[curr]){
				for(int node: scc[curr]) result.push_back(word[node]);
				for(int prev: sPrecedessor[curr]) need[prev] = true;
			}
		}
		sort(result.begin(), result.end());

		cout << result.size() << endl;
		for(auto& s: result)
			cout << s << ' ';
		cout << endl;
	}
}