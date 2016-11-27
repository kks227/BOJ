#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, K, arr[299999], prev, curr, sum;
	scanf("%d %d %d", &N, &K, &prev);
	sum = prev;
	for(int i=0; i<N-1; i++){
		scanf("%d", &curr);
		arr[i] = curr-prev;
		prev = curr;
	}
	sum = curr-sum;
	sort(arr, arr+N-1);
	for(int i=0; i<K-1; i++)
		sum -= arr[N-2-i];
	printf("%d\n", sum);
}