#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int roff[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int coff[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
const int INF = 1e9;
const long long LINF = 1e18;

int main(){
	int R, C, N = 0;
	vector<int> dist[50][50];
	scanf("%d %d", &R, &C);
	for(int r=0; r<R; r++){
		getchar();
		for(int c=0; c<C; c++){
			int k = getchar();
			if(k != '.'){
				k -= '0';
				for(int i=0; i<R; i++)
					for(int j=0; j<C; j++)
						dist[i][j].push_back(INF);
				dist[r][c][N] = 0;
				queue<int> Q;
				Q.push(r*50 + c);
				for(int i=0; !Q.empty(); i++){
					int qSize = Q.size();
					for(int j=0; j<qSize; j++){
						int cr = Q.front()/50, cc = Q.front()%50; Q.pop();
						for(int d=0; d<8; d++){
							int nr = cr+roff[d], nc = cc+coff[d];
							if(nr < 0 || nr >= R || nc < 0 || nc >= C || dist[nr][nc][N] < INF) continue;
							dist[nr][nc][N] = i/k + 1;
							Q.push(nr*50 + nc);
						}
					}
				}
				N++;
			}
		}
	}

	long long result = LINF;
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			long long temp = 0;
			for(int k=0; k<N; k++)
				temp += dist[i][j][k];
			result = min(temp, result);
		}
	}
	if(result >= INF) puts("-1");
	else printf("%lld\n", result);
}