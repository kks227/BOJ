#include <cstdio>
#include <cstring>
using namespace std;

// OOO OOX(2) OXO OXX(2) XOX
const int MOD = 1000000;
int N, cache[300][5];

int cntTetris(int pos, int status){
	if(pos > N) return 0;
	if(pos == N) return !status;
	int &ret = cache[pos][status];
	if(ret != -1) return ret;
	if(pos == N-1) return ret = 0;
	switch(status){
	case 0:
		ret = cntTetris(pos+1, 1)*2 + cntTetris(pos+1, 2) + cntTetris(pos+2, 3)*4 + cntTetris(pos+2, 4)*2;
		return ret %= MOD;
	case 1:
		ret = cntTetris(pos+3, 0)*2 + cntTetris(pos+4, 1) + cntTetris(pos+4, 2) + cntTetris(pos+1, 3)*2 + cntTetris(pos+5, 3)*2;
		return ret %= MOD;
	case 2:
		ret = cntTetris(pos+3, 0)*2;
		return ret %= MOD;
	case 3:
		ret = cntTetris(pos+2, 0) + cntTetris(pos+3, 1)*2 + cntTetris(pos+3, 2) + cntTetris(pos+4, 3);
		return ret %= MOD;
	default:
		ret = cntTetris(pos+2, 0) + cntTetris(pos+3, 1)*2 + cntTetris(pos+3, 2)*2 + cntTetris(pos+4, 3)*2;
		return ret %= MOD;
	}
	// ????
	return ret = 0;
}

int main(){
	scanf("%d", &N);
	memset(cache, -1, sizeof(cache));
	printf("%d\n", cntTetris(0, 0));
}