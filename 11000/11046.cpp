#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 1000000;

int main(){
	int N, M, S[2*MAX+1] = {0};
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", S+i);
	for(int i=N-1; i>=0; i--){
		S[i*2+1] = S[i];
		S[i*2] = -1;
	}
	N *= 2;
	S[N++] = -1;
	int R = -1, p = -1, A[2*MAX+1] = {0};
	for(int i=0; i<N; i++){
		A[i] = (i <= R ? min(A[2*p-i], R-i) : 0);
		while(i-A[i]-1 >= 0 && i+A[i]+1 < N && S[i-A[i]-1] == S[i+A[i]+1]) A[i]++;
		if(i+A[i] > R){
			R = i+A[i];
			p = i;
		}
	}

	scanf("%d", &M);
	for(int i=0; i<M; i++){
		int S, E;
		scanf("%d %d", &S, &E);
		int L = E - (--S);
		printf("%d\n", A[S*2+L] >= L);
	}
}