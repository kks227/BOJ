#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, K, arr[100000], sum = 0, result = -1000000000;
	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++)
		scanf("%d", arr+i);
	for(int i=0; i<K; i++)
		sum += arr[i];
	result = sum;
	for(int i=K; i<N; i++){
		sum += arr[i] - arr[i-K];
		result = max(result, sum);
	}
	printf("%d\n", result);
}