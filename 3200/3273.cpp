#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, arr[100000], X;
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", arr+i);
	scanf("%d", &X);
	sort(arr, arr+N);
	int result = 0;
	for(int i=0; i<N; i++)
		if(binary_search(arr, arr+N, X-arr[i])) result++;
	printf("%d\n", result/2);
}