#include <cstdio>
using namespace std;

int N, M, time[100000];

bool possible(int maxTime){
	int sum = 0, limit = M;
	for(int i=0; i<N; i++){
		sum += time[i];
		if(maxTime < sum){
			if(limit == 1) return false;
			limit--;
			sum = time[i];
		}
	}
	return true;
}

int main(){
	int sum = 0;
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		scanf("%d", time+i);
		sum += time[i];
	}
	int lo = 0, hi = sum;
	while(lo+1 < hi)
		(possible((lo+hi)/2) ? hi : lo) = (lo+hi)/2;
	printf("%d\n", hi);
}