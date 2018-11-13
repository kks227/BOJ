#include <cstdio>
using namespace std;

int main(){
	int M, N, L[1000000];
	scanf("%d %d", &M, &N);
	for(int i = 0; i < N; ++i)
		scanf("%d", L+i);

	int lo = 0, hi = 1000000001;
	while(lo+1 < hi){
		int mid = (lo+hi)/2, temp = 0;
		for(int i = 0; i < N; ++i)
			temp += L[i]/mid;
		(temp >= M ? lo : hi) = mid;
	}
	printf("%d\n", lo);
}