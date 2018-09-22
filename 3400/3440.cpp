#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
const int roff[3] = {0, -1, 1};
const int coff[3] = {1, 0, 0};
typedef pair<int, bool> edgePair;
typedef pair<char, bool> resultPair;

int main(){
	vector<string> map;
	while(1){
		int R = 0, C = 0;
		map.clear();
		while(1){
			string line;
			getline(cin, line);
			if(line[0] == '*') break;
			map.push_back(line);
			R++;
			C = max((int)line.size(), C);
		}
		if(map.empty()) break;
		
		// preprocess
		for(int i=0; i<R; i++)
			map[i].resize(C, ' ');

		// find all gates, inputs and outputs
		int G = 0;
		vector<vector<int>> gateNum(R, vector<int>(C, -1));
		vector<int> gateR1, gateR2, gateC1, gateC2;
		vector<int> gateType; // 0(input0) 1(input1) 2(and) 3(or) 4(xor) uppercase(output)
		for(int i=0; i<R; i++){
			for(int j=0; j<C; j++){
				if(gateNum[i][j] >= 0) continue;

				// gate
				if(map[i][j] == '#'){
					gateR1.push_back(i);
					gateC1.push_back(j);
					int k;
					for(k=i+1; k<R && map[k][j]=='#'; k++);
					gateR2.push_back(k-1);
					for(k=j+1; k<C && map[i][k]=='#'; k++);
					gateC2.push_back(k-1);
					bool inverse = false;
					for(int r=i; r<=gateR2[G]; r++){
						for(int c=j; c<=gateC2[G]; c++){
							gateNum[r][c] = G;
							if(map[r][c] != ' ' && map[r][c] != '#')
								gateType.push_back(map[r][c] == '&' ? 2 : (map[r][c] == '1' ? 3 : 4));
						}
						if(map[r][gateC1[G]-1] == '=') gateNum[r][gateC1[G]-1] = G;
					}
					G++;
				}

				// input
				else if(isdigit(map[i][j])){
					gateR1.push_back(i);
					gateR2.push_back(i);
					gateC1.push_back(j);
					gateC2.push_back(j);
					gateType.push_back(map[i][j] - '0');
					gateNum[i][j] = G++;
				}

				// output
				else if(isupper(map[i][j])){
					gateR1.push_back(i);
					gateR2.push_back(i);
					gateC1.push_back(j);
					gateC2.push_back(j);
					gateType.push_back(map[i][j]);
					gateNum[i][j-1] = gateNum[i][j] = G++;
				}
			}
		}

		// graphify
		vector<vector<edgePair>> adj(G);
		vector<int> outdegree(G, 0);
		for(int g=0; g<G; g++){
			queue<int> Q; // r*1200 + c*6 + d*2 + inv
			vector<vector<bool>> visited(R, vector<bool>(C, false));
			for(int i=gateR1[g]; i<=gateR2[g]; i++){
				int j = gateC2[g] + 1;
				if(map[i][j] == '='){
					Q.push(i*1200 + j*6);
					visited[i][j] = true;
				}
				else if(map[i][j] == 'o'){
					Q.push(i*1200 + (j+1)*6 + 1);
					visited[i][j+1] = true;
				}
			}

			while(!Q.empty()){
				int r = Q.front()/1200, c = Q.front()%1200/6, d = Q.front()%6/2;
				bool inv = Q.front()%2; Q.pop();
				
				int nr, nc;
				switch(map[r][c]){
				case '+':
					for(int nd=0; nd<3; nd++){
						nr = r+roff[nd];
						nc = c+coff[nd];
						if(nr < 0 || nr >= R || nc >= C) continue;
						bool connect = true;
						if(map[nr][nc] == ' ') connect = false;
						if(nd == 0 && map[nr][nc] != '-' && map[nr][nc] != '=' && map[nr][nc] != '+' && map[nr][nc] != 'x') connect = false;
						if(nd != 0 && map[nr][nc] != '|' && map[nr][nc] != '+' && map[nr][nc] != 'x') connect = false;
						if(connect && !visited[nr][nc]){
							visited[nr][nc] = true;
							Q.push(nr*1200 + nc*6 + nd*2 + inv);
						}
					}
					break;

				case '=':
					if(gateNum[r][c] >= 0){
						adj[g].push_back({gateNum[r][c], inv});
						outdegree[gateNum[r][c]]++;
						break;
					}

				default:
					nr = r+roff[d];
					nc = c+coff[d];
					if(!visited[nr][nc]){
						visited[nr][nc] = true;
						Q.push(nr*1200 + nc*6 + d*2 + inv);
					}
				}
			}
		}

		// topological sort
		queue<int> Q;
		vector<bool> val(G, false);
		for(int g=0; g<G; g++){
			if(outdegree[g] == 0) Q.push(g);
			if(gateType[g] == 1 || gateType[g] == 2) val[g] = true;
		}
		while(!Q.empty()){
			int curr = Q.front(); Q.pop();
			for(auto &e: adj[curr]){
				int next = e.first;
				bool outVal = val[curr];
				if(e.second) outVal = !outVal;

				if(gateType[next] == 2) val[next] = val[next] && outVal;
				else if(gateType[next] == 3) val[next] = val[next] || outVal;
				else if(gateType[next] == 4) val[next] = val[next] != outVal;
				else val[next] = outVal;

				if(--outdegree[next] == 0) Q.push(next);
			}
		}

		// output
		vector<resultPair> result;
		for(int g=0; g<G; g++)
			if(isupper(gateType[g])) result.push_back({gateType[g], val[g]});
		sort(result.begin(), result.end());
		for(auto &p: result)
			cout << p.first << '=' << (int)p.second << endl;
		cout << endl;
	}
}