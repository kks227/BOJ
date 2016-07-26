#include <cstdio>
#include <cstring>
using namespace std;

#define MODULA 1000000003

int N, K;
int cache[1000][1000][2];

int colorCnt(int start, int remain, int firstSet){
	int &ret = cache[start][remain-1][firstSet];
	if(ret != -1) return ret;
	if(remain == 1){
		if(start != N-1 || !firstSet) return ret = 1;
		return ret = 0;
	}

	ret = 0;
	for(int i=start+2; i<N; i++){
		if(firstSet && remain-1 > (N-i)/2) break;
		if(!firstSet && (N-i)%2 && remain-1 > (N-i+1)/2) break;
		ret += colorCnt(i, remain-1, firstSet);
		ret %= MODULA;
	}
	return ret %= MODULA;
}

int main(){

	scanf("%d %d", &N, &K);

	int result;
	memset(cache, -1, sizeof(int)*1000*1000*2);
	result = colorCnt(0, K, 1);
	for(int i=1; i<N; i++){
		result += colorCnt(i, K, 0);
		result %= MODULA;
	}
	printf("%d\n", result);

	return 0;
}