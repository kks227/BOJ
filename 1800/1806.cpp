#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, S, arr[100000];
	scanf("%d %d", &N, &S);
	for(int i=0; i<N; i++)
		scanf("%d", arr+i);
	int L = 0, R = 0, sum = 0, result = N+1;
	while(L < N){
		if(sum < S && R < N) sum += arr[R++];
		else sum -= arr[L++];
		if(sum >= S) result = min(result, R-L);
	}
	if(result > N) result = 0;
	printf("%d\n", result);
}