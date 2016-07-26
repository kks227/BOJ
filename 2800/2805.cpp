#include <cstdio>
using namespace std;

int main(){
	int N, M, height[1000000];
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++)
		scanf("%d", height+i);
	int lo = 0, hi = 1000000000;
	while(lo+1 < hi){
		int mid = (lo+hi)/2;
		long long sum = 0;
		for(int i=0; i<N; i++)
			sum += (height[i]>mid ? height[i]-mid : 0);
		(sum >= M ? lo : hi) = mid;
	}
	printf("%d\n", lo);
}