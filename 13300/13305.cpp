#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, minC, c[100000], d[100000];
	scanf("%d", &N);
	for(int i=0; i<N-1; i++)
		scanf("%d", d+i);
	for(int i=0; i<N; i++)
		scanf("%d", c+i);
	minC = c[0];

	long long result = 0;
	for(int i=0; i<N-1; i++){
		result += 1LL*minC * d[i];
		minC = min(minC, c[i+1]);
	}
	printf("%lld\n", result);
}