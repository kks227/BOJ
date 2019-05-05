#include <cstdio>
using namespace std;

int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	long long result = N;
	while(N >= M){
		N /= M;
		result += N;
	}
	printf("%lld\n", result);
}