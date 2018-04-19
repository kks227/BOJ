#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int roff[4] = {-1, 0, 1, 0};
const int coff[4] = {0, -1, 0, 1};
const int INF = 1e9;

int main(){
	while(1){
		int R, C, D = 1, sr[11], sc[11], dist[11][20][20];
		scanf("%d %d", &C, &R);
		if(R == 0) break;

		char map[20][20];
		for(int i=0; i<R; i++){
			getchar();
			for(int j=0; j<C; j++){
				map[i][j] = getchar();
				if(map[i][j] == 'o'){ sr[0] = i; sc[0] = j; }
				else if(map[i][j] == '*'){ sr[D] = i; sc[D++] = j; }
				for(int k=0; k<11; k++)
					dist[k][i][j] = INF;
			}
		}
		for(int i=0; i<D; i++){
			dist[i][sr[i]][sc[i]] = 0;
			queue<int> Q;
			Q.push(sr[i]*20 + sc[i]);
			for(int j=1; !Q.empty(); j++){
				int qSize = Q.size();
				for(int k=0; k<qSize; k++){
					int r = Q.front()/20, c = Q.front()%20; Q.pop();
					for(int d=0; d<4; d++){
						int nr = r+roff[d], nc = c+coff[d];
						if(nr < 0 || nr >= R || nc < 0 || nc >= C || map[nr][nc] == 'x' || dist[i][nr][nc] < INF) continue;
						dist[i][nr][nc] = j;
						Q.push(nr*20 + nc);
					}
				}
			}
		}
		D--;

		long long result = INF;
		int seq[10];
		for(int i=0; i<D; i++)
			seq[i] = i+1;
		do{
			long long temp = 0;
			for(int i=0; i<D; i++){
				int r = sr[seq[i]], c = sc[seq[i]];
				temp += dist[i?seq[i-1]:0][r][c];
			}
			result = min(temp, result);
		}while(next_permutation(seq, seq+D));
		if(result == INF) puts("-1");
		else printf("%lld\n", result);
	}
}