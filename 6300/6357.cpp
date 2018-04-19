#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int main(){
	while(1){
		int N;
		cin >> N;
		if(N == 0) break;

		cin.ignore(1024, '\n');
		vector<int> adj[100];
		while(1){
			string line;
			getline(cin, line);
			if(line[0] == '0') break;

			stringstream ss(line);
			int u, v;
			ss >> u;
			while(ss >> v){
				adj[u-1].push_back(v-1);
				adj[v-1].push_back(u-1);
			}
		}

		int result = 0;
		for(int i=0; i<N; i++){
			int cnt = 1;
			bool visited[100] = {false,};
			visited[!i] = true;
			queue<int> Q;
			Q.push(!i);
			while(!Q.empty()){
				int curr = Q.front(); Q.pop();
				for(int next: adj[curr]){
					if(next != i && !visited[next]){
						cnt++;
						visited[next] = true;
						Q.push(next);
					}
				}
			}
			if(cnt < N-1) result++;
		}
		cout << result << endl;
	}
}