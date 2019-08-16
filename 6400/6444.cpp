#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_R = 1000;
const int MAX_C = 18278;

inline int parseColNum(string s){
	if(s.size() == 1) return s[0]-'A';
	if(s.size() == 2) return (s[0]-'A')*26 + s[1]-'A' + 26;
	return ((s[0]-'A')*26 + s[1]-'A')*26 + s[2]-'A' + 27*26;
};

inline int parseCellNum(string s){
	for(int i = 0; ; ++i)
		if(s[i] <= '9') return (stoi(s.substr(i))-1)*MAX_C + parseColNum(s.substr(0, i));
	return -1; // dummy
}



int main(){
	int T;
	cin >> T;
	for(int t = 0; t < T; ++t){
		int R, C;
		cin >> C >> R;
		vector<vector<int>> val(R, vector<int>(C, 0));
		vector<vector<int>> indegree(R, vector<int>(C, 0));
		vector<vector<vector<int>>> adj(R, vector<vector<int>>(C));
		for(int i = 0; i < R; ++i){
			for(int j = 0; j < C; ++j){
				string s;
				cin >> s;
				if(s[0] == '='){
					int k = 1, L = s.size(), x;
					for(int l = k; l < L; ++l){
						if(s[l] == '+'){
							x = parseCellNum(s.substr(k, l));
							adj[x/MAX_C][x%MAX_C].push_back(i*MAX_C + j);
							++indegree[i][j];
							k = l+1;
						}
					}
					x = parseCellNum(s.substr(k, L));
					adj[x/MAX_C][x%MAX_C].push_back(i*MAX_C + j);
					++indegree[i][j];
				}
				else val[i][j] = stoi(s);
			}
		}

		queue<int> Q;
		for(int i = 0; i < R; ++i)
			for(int j = 0; j < C; ++j)
				if(indegree[i][j] == 0) Q.push(i*MAX_C + j);
		while(!Q.empty()){
			int r = Q.front()/MAX_C, c = Q.front()%MAX_C;
			Q.pop();
			for(int k: adj[r][c]){
				int nr = k/MAX_C, nc = k%MAX_C;
				val[nr][nc] += val[r][c];
				if(--indegree[nr][nc] == 0) Q.push(k);
			}
		}

		for(int i = 0; i < R; ++i){
			for(int j = 0; j < C; ++j)
				cout << val[i][j] << ' ';
			cout << '\n';
		}
	}
}