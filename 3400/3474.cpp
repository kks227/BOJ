#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N, result = 0;
		scanf("%d", &N);
		for(long long i=5; i<=N; i*=5)
			result += N/i;
		printf("%d\n", result);
	}
}