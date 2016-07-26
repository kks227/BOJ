#include <cstdio>
using namespace std;

int main(){
	int T;
	unsigned long long C[21][211] = {0};
	scanf("%d", &T);
	C[1][0] = C[1][1] = 1;
	for(int i=2; i<=20; i++){
		for(int j=0; j<211; j++)
			for(int k=0; k<=i; k++)
				C[i][j+k] += C[i-1][j];
	}
	for(int t=0; t<T; t++){
		int K, N;
		scanf("%d %d", &K, &N);
		printf("%lld\n", C[K][N]);
	}
}