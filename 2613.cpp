#include <cstdio>
using namespace std;

int main(){
	int N, M, val[300], lo = 0, hi = 0;
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		scanf("%d", val+i);
		if(lo < val[i]) lo = val[i];
		hi += val[i];
	}
	lo--;
	while(lo+1 < hi){
		int mid = (lo+hi)/2;
		int sum = 0, group = 1;
		bool success = true;
		for(int i=0; i<N; i++){
			if(sum+val[i] > mid || N-i==M-group){
				if(group == M){
					success = false;
					break;
				}
				group++;
				sum = val[i];
			}
			else sum += val[i];
		}
		(success ? hi : lo) = mid;
	}
	printf("%d\n", hi);
	int sum = 0, cnt = 0, group = 1;
	for(int i=0; i<N; i++){
		if(sum+val[i] > hi || N-i==M-group){
			printf("%d ", cnt);
			cnt = 1;
			group++;
			sum = val[i];
		}
		else{
			sum += val[i];
			cnt++;
		}
	}
	printf("%d\n", cnt);
}