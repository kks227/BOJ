#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		int N;
		scanf("%d", &N);
		printf("%lld\n", 1LL*N*(N+1)*(2*N+1)/6);
	}
}