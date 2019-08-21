#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 100000;
const int MAX_D = 30;

int main(){
	int N, K, M, s[MAX], next[MAX][MAX_D];
	scanf("%d %d %d", &K, &N, &M);
	--M;
	for(int i = 0; i < K; ++i){
		scanf("%d", s+i);
		--s[i];
	}
	memset(next, -1, sizeof(next));
	for(int i = 0; i < N; ++i){
		scanf("%d", &next[i][0]);
		--next[i][0];
	}
	for(int j = 1; j < MAX_D; ++j)
		for(int i = 0; i < N; ++i)
			next[i][j] = next[ next[i][j-1] ][j-1];
	for(int i = 0; i < K; ++i){
		int u = s[i], w = M;
		for(int j = MAX_D-1; j >= 0; --j){
			if(w >= 1<<j){
				w -= 1<<j;
				u = next[u][j];
			}
		}
		printf("%d ", u+1);
	}
}