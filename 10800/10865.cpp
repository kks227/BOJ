#include <cstdio>
using namespace std;

int main(){
	int N, M, cnt[100000] = {0};
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		int A, B;
		scanf("%d %d", &A, &B);
		cnt[A-1]++;
		cnt[B-1]++;
	}
	for(int i=0; i<N; i++)
		printf("%d\n", cnt[i]);
}