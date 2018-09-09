#include <cstdio>
#include <cctype>
#include <queue>
#include <unordered_set>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int main(){
	int N, R, C, L;
	char map[10][10];
	unsigned int start = 0;
	scanf("%d %d %d %d", &N, &C, &R, &L);
	for(int i=0; i<R; i++){
		getchar();
		for(int j=0; j<C; j++){
			map[i][j] = getchar();
			if(isdigit(map[i][j])){
				int k = map[i][j]-'1';
				start += i*(1<<4+k*8) + j*(1<<k*8);
			}
		}
	}

	queue<unsigned int> Q;
	Q.push(start);
	unordered_set<unsigned int> visited;
	visited.insert(start);
	for(int i=0; i<L; i++){
		int qSize = Q.size();
		for(int j=0; j<qSize; j++){
			int r[4], c[4], temp = Q.front();
			Q.pop();
			for(int k=0; k<4; k++){
				r[k] = temp%256/16;
				c[k] = temp%256%16;
				temp /= 256;
			}

			for(int k=0; k<N; k++){
				for(int d=0; d<4; d++){
					int pr = r[k], pc = c[k];
					while(1){
						int nr = r[k]+roff[d], nc = c[k]+coff[d];
						if(nr < 0 || nr >= R || nc < 0 || nc >= C || map[nr][nc] == 'W') break;
						bool flag = false;
						for(int l=0; l<N; l++)
							if(l != k && r[l] == nr && c[l] == nc) flag = true;
						if(flag) break;

						r[k] = nr; c[k] = nc;
					}
					if(map[r[0]][c[0]] == 'X'){
						printf("%d\n", i+1);
						return 0;
					}

					int next = 0;
					for(int l=0; l<N; l++)
						next += r[l]*(1<<4+l*8) + c[l]*(1<<l*8);
					if(visited.find(next) == visited.end()){
						visited.insert(next);
						Q.push(next);
					}

					r[k] = pr; c[k] = pc;
				}
			}
		}
	}
	puts("NO SOLUTION");
}