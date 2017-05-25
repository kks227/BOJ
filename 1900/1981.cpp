#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};
const int INF = 1e9;

int main(){
	int N, val[100][100];
	scanf("%d", &N);
	vector<int> V;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			scanf("%d", &val[i][j]);
			V.push_back(val[i][j]);
		}
	}
	sort(V.begin(), V.end());
	V.erase(unique(V.begin(), V.end()), V.end());

	int lo = 0, hi = 0, result = INF;
	while(lo < V.size()){
		bool visited[100][100] = {0};
		queue<int> Q;
		if(V[lo] <= val[0][0] && val[0][0] <= V[hi]){
			visited[0][0] = true;
			Q.push(0);
		}
		int cnt = 0;
		while(!Q.empty()){
			int r = Q.front()/100, c = Q.front()%100; Q.pop();
			for(int d=0; d<4; d++){
				int nr = r+roff[d], nc = c+coff[d];
				if(nr < 0 || nr >= N || nc < 0 || nc >= N || visited[nr][nc]) continue;
				if(V[lo] <= val[nr][nc] && val[nr][nc] <= V[hi]){
					visited[nr][nc] = true;
					Q.push(nr*100 + nc);
				}
			}
		}
		if(visited[N-1][N-1]){
			result = min(result, V[hi]-V[lo]);
			lo++;
		}
		else if(hi < V.size()-1) hi++;
		else break;
	}
	printf("%d\n", result);
}