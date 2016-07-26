#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, M, arr[100];
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++)
		arr[i] = i+1;
	for(int i=0; i<M; i++){
		int p, q, r;
		scanf("%d %d %d", &p, &q, &r);
		rotate(arr+p-1, arr+r-1, arr+q);
	}
	for(int i=0; i<N; i++)
		printf("%d ", arr[i]);
}