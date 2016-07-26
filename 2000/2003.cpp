#include <cstdio>
using namespace std;

int main(){
	int N, M, arr[10000];
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++)
		scanf("%d", arr+i);
	int result = 0, sum = 0, lo = 0, hi = 0;
	while(1){
		if(sum >= M) sum -= arr[lo++];
		else if(hi == N) break;
		else sum += arr[hi++];
		if(sum == M) result++;
	}
	printf("%d\n", result);
}