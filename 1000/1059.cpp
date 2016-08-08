#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int M, arr[50], N;
	scanf("%d", &M);
	for(int i=0; i<M; i++)
		scanf("%d", arr+i);
	scanf("%d", &N);
	sort(arr, arr+M);
	int R = lower_bound(arr, arr+M, N) - arr;
	if(arr[R] == N) puts("0");
	else if(R == 0) printf("%d\n", N*(arr[0]-N) - 1);
	else printf("%d\n", (N-arr[R-1])*(arr[R]-N) - 1);
}