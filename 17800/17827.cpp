#include <cstdio>
using namespace std;
const int MAX = 200000;

int main(){
	int N, M, V, C[MAX];
	scanf("%d %d %d", &N, &M, &V);
	int pSize = --V, cSize = N - pSize;
	for(int i = 0; i < N; ++i)
		scanf("%d", C+i);
	for(int i = 0; i < M; ++i){
		int K;
		scanf("%d", &K);
		if(K < pSize) printf("%d\n", C[K]);
		else printf("%d\n", C[(K-pSize)%cSize+pSize]);
	}
}