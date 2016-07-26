#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, M, L, dist[102];
	scanf("%d %d %d", &N, &M, &L);
	for(int i=0; i<N; i++)
		scanf("%d", dist+i);
	dist[N++] = 0;
	dist[N++] = L;
	sort(dist, dist+N);
	int lo = 0, hi = L;
	while(lo+1 < hi){
		int mid = (lo+hi)/2;
		int remain = M;
		for(int i=0; i<N-1; i++){
			if(dist[i+1]-dist[i] > mid){
				remain -= (dist[i+1]-dist[i]-1)/mid;
				if(remain < 0) break;
			}
		}
		(remain<0 ? lo : hi) = mid;
	}
	printf("%d\n", hi);
}