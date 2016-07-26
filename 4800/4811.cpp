#include <cstdio>
using namespace std;

long long cache[31][31];

long long strCnt(int whole, int half){
	long long &ret = cache[whole][half];
	if(ret) return ret;
	if(whole+half == 1) return ret = 1;
	if(whole) ret += strCnt(whole-1, half+1);
	if(half) ret += strCnt(whole, half-1);
	return ret;
}

int main(){

	int N;
	while(1){
		scanf("%d", &N);
		if(N == 0) break;
		printf("%lld\n", strCnt(N, 0));
	}

	return 0;
}