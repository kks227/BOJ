#include <cstdio>
using namespace std;

int main(){
	int N, M, K, X[1000];
	scanf("%d %d %d", &N, &M, &K);
	for(int i=0; i<M; i++)
		scanf("%d", X+i);
	int lo = 1, hi = N+1;
	while(lo+1 < hi){
		int mid = (lo+hi)/2;
		bool flag = false;
		for(int i=0; i<M; i++){
			int cnt = 0, prev = i, curr = i+1;
			while(curr < M){
				if(X[curr]-X[prev] >= mid){
					prev = curr;
					if(++cnt == K) break;
				}
				curr++;
			}
			if(N-X[prev]+X[i] >= mid) cnt++;
			if(cnt >= K){
				flag = true;
				break;
			}
		}
		(flag ? lo : hi) = mid;
	}
	printf("%d\n", lo);
}