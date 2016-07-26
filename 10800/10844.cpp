#include <cstdio>
#include <cstring>
using namespace std;

const int MOD = 1000000000;
int N, cache[100][10];

int stair(int pos, int val){
	if(pos == N) return 1;
	int &ret = cache[pos][val];
	if(ret != -1) return ret;
	ret = 0;
	if(val > 0){
		ret += stair(pos+1, val-1);
		ret %= MOD;
	}
	if(val < 9){
		ret += stair(pos+1, val+1);
		ret %= MOD;
	}
	return ret;
}

int main(){
	scanf("%d", &N);
	memset(cache, -1, sizeof(cache));
	int result = 0;
	for(int i=1; i<10; i++){
		result += stair(1, i);
		result %= MOD;
	}
	printf("%d\n", result);
}