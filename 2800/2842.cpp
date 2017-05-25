#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int roff[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int coff[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int INF = 1e9;

int main(){
	int N, H[50][50], sr, sc, K = 0;
	char map[50][50];
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		getchar();
		for(int j=0; j<N; j++){
			map[i][j] = getchar();
			if(map[i][j] == 'P'){
				sr = i;
				sc = j;
			}
			else if(map[i][j] == 'K') K++;
		}
	}
	vector<int> V;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			scanf("%d", &H[i][j]);
			V.push_back(H[i][j]);
		}
	}
	sort(V.begin(), V.end());
	V.erase(unique(V.begin(), V.end()), V.end());

	int lo = 0, hi = 0, result = INF;
	while(lo < V.size()){
		bool visited[50][50] = {0};
		queue<int> Q;
		if(V[lo] <= H[sr][sc] && H[sr][sc] <= V[hi]){
			visited[sr][sc] = true;
			Q.push(sr*50 + sc);
		}
		int cnt = 0;
		while(!Q.empty()){
			int r = Q.front()/50, c = Q.front()%50; Q.pop();
			for(int d=0; d<8; d++){
				int nr = r+roff[d], nc = c+coff[d];
				if(nr < 0 || nr >= N || nc < 0 || nc >= N || visited[nr][nc]) continue;
				if(V[lo] <= H[nr][nc] && H[nr][nc] <= V[hi]){
					visited[nr][nc] = true;
					Q.push(nr*50 + nc);
					if(map[nr][nc] == 'K') cnt++;
				}
			}
		}
		if(cnt == K){
			result = min(result, V[hi]-V[lo]);
			lo++;
		}
		else if(hi < V.size()-1) hi++;
		else break;
	}
	printf("%d\n", result);
}