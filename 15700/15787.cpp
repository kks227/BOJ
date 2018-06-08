#include <cstdio>
#include <unordered_set>
using namespace std;
const int MOD = 1<<20;

int main(){
	int N, M, A[100000] = {0};
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		int q, t, x;
		scanf("%d %d", &q, &t);
		t--;
		if(q < 3){
			scanf("%d", &x);
			x--;
		}
		switch(q){
		case 1:
			A[t] |= 1<<x;
			break;
		case 2:
			A[t] &= MOD - (1<<x) - 1;
			break;
		case 3:
			A[t] = (A[t]<<1) % MOD;
			break;
		default:
			A[t] >>= 1;
		}
	}
	unordered_set<int> S;
	for(int i=0; i<N; i++)
		S.insert(A[i]);
	printf("%d\n", S.size());
}