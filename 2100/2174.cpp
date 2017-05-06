#include <cstdio>
#include <queue>
using namespace std;
// N E S W
const int roff[4] = {1, 0, -1, 0};
const int coff[4] = {0, 1, 0, -1};

int main(){
	int R, C, N, M, r[100], c[100], d[100];
	scanf("%d %d %d %d", &C, &R, &N, &M);
	for(int i=0; i<N; i++){
		int u, v;
		char op;
		scanf("%d %d %c", &u, &v, &op);
		r[i] = v-1; c[i] = u-1;
		if(op == 'N') d[i] = 0;
		else if(op == 'E') d[i] = 1;
		else if(op == 'S') d[i] = 2;
		else d[i] = 3;
	}
	bool fail = false;
	for(int i=0; i<M; i++){
		int n, m;
		char op;
		scanf("%d %c %d", &n, &op, &m);
		if(fail) continue;
		n--;

		if(op == 'L') d[n] = (d[n]+3*m)%4;
		else if(op == 'R') d[n] = (d[n]+m)%4;
		else{
			for(int j=0; j<m; j++){
				int nr = r[n]+roff[d[n]], nc = c[n]+coff[d[n]];
				if(nr < 0 || nr >= R || nc < 0 || nc >= C){
					fail = true;
					printf("Robot %d crashes into the wall\n", n+1);
					break;
				}
				for(int k=0; k<N; k++){
					if(i == k) continue;
					if(r[k] == nr && c[k] == nc){
						fail = true;
						printf("Robot %d crashes into robot %d\n", n+1, k+1);
						break;
					}
				}
				if(fail) break;
				r[n] = nr; c[n] = nc;
			}
		}
	}
	if(!fail) puts("OK");
}