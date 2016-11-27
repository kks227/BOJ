#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N, M, mod = 1, X = 0, Y = 0, Z = 0, result = 0, arr[100];
		scanf("%d %d", &N, &M);
		for(int i=0; i<M; i++){
			int val;
			scanf("%d", &val);
			X = X*10 + val;
		}
		for(int i=0; i<M; i++){
			int val;
			scanf("%d", &val);
			Y = Y*10 + val;
			mod *= 10;
		}
		for(int i=0; i<N; i++)
			scanf("%d", arr+i);
		for(int i=N-M+1; i<N; i++)
			Z = Z*10 + arr[i];
		for(int i=0; i<N; i++){
			Z = (Z*10LL)%mod + arr[i];
			if(X <= Z && Z <= Y) result++;
		}
		printf("%d\n", result);
	}
}