#include <cstdio>
using namespace std;

int main(){
	int N, K, cnt[2][6] = {0};
	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++){
		int S, Y;
		scanf("%d %d", &S, &Y);
		cnt[S][Y-1]++;
	}
	int result = 0;
	for(int i=0; i<2; i++)
		for(int j=0; j<6; j++)
			result += (cnt[i][j]+K-1)/K;
	printf("%d\n", result);
}