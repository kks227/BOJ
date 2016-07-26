#include <cstdio>
using namespace std;

int main(){
	int N, M, arr[100] = {0};
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		int p, q, r;
		scanf("%d %d %d", &p, &q, &r);
		for(int j=p; j<=q; j++)
			arr[j-1] = r;
	}
	for(int i=0; i<N; i++)
		printf("%d ", arr[i]);
}