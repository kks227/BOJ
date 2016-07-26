#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, use[20], cache[20][1820];

int minMoving(int round, int status){
	if(round == M) return 0;
	int &ret = cache[round][status];
	if(ret != -1) return ret;
	int s1 = status/100, s2 = status%100;
	if(use[round]==s1 || use[round]==s2) return ret = minMoving(round+1, status);
	if(use[round] < s1) return ret = minMoving(round+1, use[round]*100+s2)+s1-use[round];
	if(use[round] > s2) return ret = minMoving(round+1, s1*100+use[round])+use[round]-s2;
	return ret = min(minMoving(round+1, use[round]*100+s2)+use[round]-s1, minMoving(round+1, s1*100+use[round])+s2-use[round]);
}

int main(){
	int s1, s2;
	scanf("%d %d %d %d", &N, &s1, &s2, &M);
	if(s1>s2) swap(s1, s2);
	s1--; s2--;
	for(int i=0; i<M; i++){
		scanf("%d", use+i);
		use[i]--;
	}
	memset(cache, -1, sizeof(cache));
	printf("%d\n", minMoving(0, s1*100+s2));
}