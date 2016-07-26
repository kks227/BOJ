#include <cstdio>
#include <cstring>
using namespace std;

const int MOD = 10007;
int N, cache[1000][10];

int inc(int pos, int val){
	if(pos == N) return 1;
	int &ret = cache[pos][val];
	if(ret) return ret;
	ret = inc(pos+1, val);
	if(val < 9) ret = (ret + inc(pos, val+1)) % MOD;
	return ret;
}

int main(){
	scanf("%d", &N);
	printf("%d\n", inc(0, 0));
}