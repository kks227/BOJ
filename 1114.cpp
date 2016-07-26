#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int L, K, C, pos[10000];
	scanf("%d %d %d", &L, &K, &C);
	for(int i=0; i<K; i++)
		scanf("%d", pos+i);
	sort(pos, pos+K);
	int lo = 0, hi = L;
	while(lo+1 < hi){
		int mid = (lo+hi)/2;
		int remain = C;
		bool success = true;
		if(pos[0]>mid || L-pos[K-1]>mid) success = false;
		else{
			int sum = pos[0];
			for(int i=0; i<K-1; i++){
				if(pos[i+1]-pos[i] > mid){
					success = false;
					break;
				}
				if(sum+pos[i+1]-pos[i] > mid){
					if(!remain){
						success = false;
						break;
					}
					remain--;
					sum = pos[i+1]-pos[i];
				}
				else sum += pos[i+1]-pos[i];
			}
			if(success && sum+L-pos[K-1] > mid && !remain) success = false;
		}
		(success ? hi : lo) = mid;
	}
	printf("%d ", hi);
	int sum = L-pos[K-1], remain = C;
	for(int i=K-2; i>=0; i--){
		if(sum+pos[i+1]-pos[i] > hi){
			sum = pos[i+1]-pos[i];
			C--;
		}
		else sum += pos[i+1]-pos[i];
	}
	printf("%d\n", C ? pos[0] : sum+pos[0]);
}