#include <cstdio>
using namespace std;

int main(){
	int N, M, L, sum = 0;
	scanf("%d %d %d", &N, &M, &L);
	for(int i = 0; i < N; ++i){
		int x;
		scanf("%d", &x);
		sum += x;
	}
	if(sum == M) puts("0");
	else puts(sum < L && M-sum < L || sum > M ? "-1" : "1");
}