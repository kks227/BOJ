#include <cstdio>
using namespace std;

int main(){
	int N, K, B, val[100];
	scanf("%d %d %d", &N, &K, &B);
	for(int i=0; i<N; i++)
		scanf("%d", val+i);
	int sum = 0;
	for(int i=0; i<K; i++)
		sum += val[(B+i-1)%N];
	printf("%d\n", sum);
}