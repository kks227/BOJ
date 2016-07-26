#include <cstdio>
#include <cstring>
using namespace std;

const int MOD = 1000000;
int N, cache[100][100][2];

int cntRow(int Lcnt, int Rcnt, bool bigger){
	int &ret = cache[Lcnt][Rcnt][bigger];
	if(ret != -1) return ret;
	if(Lcnt+Rcnt == 0) return ret = 1;
	ret = 0;
	if(Lcnt+Rcnt==N-1 || bigger){
		for(int i=0; i<Lcnt; i++)
			ret = (ret + cntRow(i, Lcnt+Rcnt-1-i, false)) % MOD;
	}
	if(Lcnt+Rcnt==N-1 || !bigger){
		for(int i=0; i<Rcnt; i++)
			ret = (ret + cntRow(Lcnt+Rcnt-1-i, i, true)) % MOD;
	}
	return ret;
}

int main(){
	scanf("%d", &N);
	memset(cache, -1, sizeof(cache));
	int result = 0;
	for(int i=0; i<N; i++)
		result = (result + cntRow(i, N-i-1, false)) % MOD;
	printf("%d\n", result);
}