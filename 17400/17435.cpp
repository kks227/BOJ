#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 500001;
const int MAX_D = 19;

int main(){
	int M, next[MAX][MAX_D];
	memset(next, -1, sizeof(next));
	scanf("%d", &M);
	for(int i = 1; i <= M; ++i)
		scanf("%d", &next[i][0]);
	for(int j = 1; j < MAX_D; ++j)
		for(int i = 1; i <= M; ++i)
			next[i][j] = next[ next[i][j-1] ][j-1];

	int Q;
	scanf("%d", &Q);
	for(int i = 0; i < Q; ++i){
		int n, x;
		scanf("%d %d", &n, &x);
		for(int j = MAX_D-1; j >= 0; --j){
			if(n >= 1<<j){
				n -= 1<<j;
				x = next[x][j];
			}
		}
		printf("%d\n", x);
	}
}