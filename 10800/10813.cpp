#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, M, arr[100];
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++)
		arr[i] = i+1;
	for(int i=0; i<M; i++){
		int p, q;
		scanf("%d %d", &p, &q);
		swap(arr[p-1], arr[q-1]);
	}
	for(int i=0; i<N; i++)
		printf("%d ", arr[i]);
}