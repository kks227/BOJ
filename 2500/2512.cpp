#include <cstdio>
#include <algorithm>
using namespace std;

int N, M, cost[10000];

bool possible(int limit){
	int sum = 0;
	for(int i=0; i<N; i++)
		sum += min(limit, cost[i]);
	return sum <= M;
}

int main(){
	scanf("%d", &N);
	int mVal = 0;
	for(int i=0; i<N; i++){
		scanf("%d", cost+i);
		mVal = max(mVal, cost[i]);
	}
	scanf("%d", &M);
	if(possible(mVal)){
		printf("%d\n", mVal);
		return 0;
	}
	int lo = 0, hi = M;
	while(lo+1 < hi){
		int mid = (lo+hi)/2;
		if(possible(mid)) lo = mid;
		else hi = mid;
	}
	printf("%d\n", lo);
}