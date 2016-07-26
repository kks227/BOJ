#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, M, K, result = 0;
	scanf("%d %d %d", &N, &M, &K);
	for(int i=0; i<=K; i++){
		int n = N-i, m = M-K+i;
		if(n<0 || m<0) continue;
		result = max(result, min(n/2, m));
	}
	printf("%d\n", result);
}