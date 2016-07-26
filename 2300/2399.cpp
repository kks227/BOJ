#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, arr[10000];
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", arr+i);
	sort(arr, arr+N);
	long long sum = arr[0], result = 0;
	for(int i=1; i<N; i++){
		result += arr[i]*1LL*i-sum;
		sum += arr[i];
	}
	printf("%lld\n", result*2);
}