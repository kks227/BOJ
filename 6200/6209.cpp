#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 50000;

int main(){
	int D, N, M, d[MAX];
	scanf("%d %d %d", &D, &N, &M);
	for(int i = 0; i < N; ++i)
		scanf("%d", d+i);
	sort(d, d+N);
	int lo = 0, hi = D+1;
	while(lo+1 < hi){
		int mid = (lo+hi)/2, cnt = 0, prev = 0;
		for(int i = 0; i < N; ++i){
			if(d[i]-prev < mid) ++cnt;
			else prev = d[i];
		}
		if(D-prev < mid) ++cnt;
		(cnt <= M ? lo : hi) = mid;
	}
	printf("%d\n", lo);
}