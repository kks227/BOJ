#include <cstdio>
using namespace std;
const int MAX = 100000;

int main(){
	int N, Q, pSum[MAX+1][3] = {0};
	scanf("%d %d", &N, &Q);
	for(int i = 0; i < N; ++i){
		int val;
		scanf("%d", &val);
		for(int j = 0; j < 3; ++j)
			pSum[i+1][j] = pSum[i][j] + (val-1 == j);
	}
	for(int i = 0; i < Q; ++i){
		int s, e;
		scanf("%d %d", &s, &e);
		--s;
		for(int j = 0; j < 3; ++j)
			printf("%d ", pSum[e][j] - pSum[s][j]);
		puts("");
	}
}