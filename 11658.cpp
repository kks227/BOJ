#include <cstdio>
using namespace std;

int N, T[1025][1025], val[1025][1025];

void update(int x, int y, int k){
	int r = x;
	while(r <= N){
		int c = y;
		while(c <= N){
			T[r][c] += k;
			c += (c & -c);
		}
		r += (r & -r);
	}
}

int sum(int x, int y){
	int result = 0;
	int c = y;
	while(c){
		int r = x;
		while(r){
			result += T[r][c];
			r -= (r & -r);
		}
		c -= (c & -c);
	}
	return result;
}



int main(){
	int M;
	scanf("%d %d", &N, &M);

	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			scanf("%d", &val[i][j]);
			update(i, j, val[i][j]);
		}
	}

	for(int i=0; i<M; i++){
		int w;
		scanf("%d", &w);
		if(w == 0){
			int x, y, c;
			scanf("%d %d %d", &x, &y, &c);
			update(x, y, c-val[x][y]);
			val[x][y] = c;
		}
		else{
			int r1, c1, r2, c2;
			scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
			printf("%d\n", sum(r2, c2) - sum(r2, c1-1) - sum(r1-1, c2) + sum(r1-1, c1-1));
		}
	}
}