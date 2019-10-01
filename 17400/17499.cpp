#include <cstdio>
using namespace std;
const int MAX = 200000;

int main(){
	int N, Q, A[MAX], S = 0;
	scanf("%d %d", &N, &Q);
	for(int i = 0; i < N; ++i)
		scanf("%d", A+i);
	for(int q = 0; q < Q; ++q){
		int op;
		scanf("%d", &op);
		if(op == 1){
			int i, x;
			scanf("%d %d", &i, &x);
			--i;
			A[(i+N-S)%N] += x;
		}
		else{
			int s;
			scanf("%d", &s);
			if(op == 3) s *= -1;
			S = (S + N + s) % N;
		}
	}
	for(int i = 0; i < N; ++i)
		printf("%d ", A[(i+N-S)%N]);
}