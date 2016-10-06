#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, M, arr[500000];
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", arr+i);
	sort(arr, arr+N);
	scanf("%d", &M);
	for(int i=0; i<M; i++){
		int val, *p, *q;
		scanf("%d", &val);
		p = lower_bound(arr, arr+N, val);
		q = upper_bound(arr, arr+N, val);
		printf("%d ", q-p);
	}
}