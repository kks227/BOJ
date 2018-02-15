#include <cstdio>
using namespace std;

int main(){
	int N, K, sum[5] = {0}, result = 0;
	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++){
		int S, Y;
		scanf("%d %d", &S, &Y);
		if(Y < 3) sum[4]++;
		else sum[(Y-3)/2*2 + S]++;
	}
	for(int i=0; i<5; i++)
		result += (sum[i]+K-1)/K;
	printf("%d\n", result);
}