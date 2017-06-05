#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int K, N;
		scanf("%d %d", &K, &N);
		int S = N*(N+1)/2;
		printf("%d %d %d %d\n", K, S, S*2-N, S*2);
	}
}