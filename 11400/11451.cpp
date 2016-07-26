#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
typedef pair<int, int> P;
const int IMPOSSIBLE = 0x7FFFFFFF;
int offset[2][4] = {{-1, 1, 0, 0}, {0, 0, -1, 1}};
char dirchar[4] = {'N', 'S', 'W', 'E'};

void lexicog(int &r1, int &c1, int &r2, int &c2){
	if(P(r1, c1) > P(r2, c2)){
		swap(r1, r2);
		swap(c1, c2);
	}
}

inline int vals2tup(int r1, int c1, int r2, int c2){
	return r1*1000000 + c1*10000 + r2*100 + c2;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int M, N, prev[50][50][50][50];
		char map[50][50], prevMove[50][50][50][50];
		scanf("%d %d", &M, &N);
		int p = 0, pr[2], pc[2];
		for(int i=0; i<M; i++){
			getchar();
			for(int j=0; j<N; j++){
				map[i][j] = getchar();
				if(map[i][j] == 'P'){
					map[i][j] = '.';
					pr[p] = i;
					pc[p] = j;
					p++;
				}
			}
		}

		bool visited[50][50][50][50];
		memset(visited, 0, sizeof(visited));
		lexicog(pr[0], pc[0], pr[1], pc[1]);
		int start = vals2tup(pr[0], pc[0], pr[1], pc[1]);
		queue<int> Q;
		Q.push(start);
		visited[pr[0]][pc[0]][pr[1]][pc[1]] = true;

		bool success = false;
		int finish = -1;
		while(!Q.empty()){
			int current = Q.front();
			Q.pop();
			int r1 = current/1000000;
			int c1 = current%1000000/10000;
			int r2 = current%10000/100;
			int c2 = current%100;

			if(r1==r2 && c1==c2){
				success = true;
				finish = current;
				break;
			}

			for(int d=0; d<4; d++){
				int nr1 = (r1 + offset[0][d] + M) % M;
				int nc1 = (c1 + offset[1][d] + N) % N;
				int nr2 = (r2 + offset[0][d] + M) % M;
				int nc2 = (c2 + offset[1][d] + N) % N;
				if(map[nr1][nc1]=='G' || map[nr2][nc2]=='G') continue;

				if(map[nr1][nc1]=='X'){
					nr1 = r1;
					nc1 = c1;
				}
				if(map[nr2][nc2]=='X'){
					nr2 = r2;
					nc2 = c2;
				}
				lexicog(nr1, nc1, nr2, nc2);

				if(visited[nr1][nc1][nr2][nc2]) continue;
				visited[nr1][nc1][nr2][nc2] = true;
				Q.push(vals2tup(nr1, nc1, nr2, nc2));
				prev[nr1][nc1][nr2][nc2] = current;
				prevMove[nr1][nc1][nr2][nc2] = dirchar[d];
			}
		}

		if(success){
			vector<char> trace;
			int current = finish;
			while(current != start){
				int r1 = current/1000000;
				int c1 = current%1000000/10000;
				int r2 = current%10000/100;
				int c2 = current%100;
				trace.push_back( prevMove[r1][c1][r2][c2] );
				current = prev[r1][c1][r2][c2];
			}
			int result = trace.size();
			printf("%d ", result);
			for(int i=result-1; i>=0; i--)
				putchar(trace[i]);
			puts("");
		}
		else puts("IMPOSSIBLE");
	}
}