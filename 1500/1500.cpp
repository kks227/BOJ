#include <cstdio>
using namespace std;

int main(){
	int S, K;
	scanf("%d %d", &S, &K);
	int p = S/K, q = S%K;
	long long result = 1;
	for(int i=0; i<K; i++)
		result *= (i<K-q ? p : p+1);
	printf("%lld\n", result);
}