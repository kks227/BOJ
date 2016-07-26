#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int pn, cache[1121][188][15];
vector<int> prime;

int pSumCnt(int n, int pos, int k){
	int &ret = cache[n][pos][k];
	if(ret != -1) return ret;
	if(n == 0) return ret = (k==0);
	if(k == 0) return ret = 0;
	if(pos == pn) return ret = 0;
	ret = pSumCnt(n, pos+1, k);
	if(n >= prime[pos]) ret += pSumCnt(n-prime[pos], pos+1, k-1);
	return ret;
}

int main(){
	prime.push_back(2);
	bool np[1120] = {0};
	for(int i=3; i<1120; i+=2){
		if(np[i]) continue;
		prime.push_back(i);
		for(int j=i*i; j<1120; j+=i*2)
			np[j] = true;
	}
	pn = prime.size();
	reverse(prime.begin(), prime.end());
	memset(cache, -1, sizeof(cache));
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N, K;
		scanf("%d %d", &N, &K);
		printf("%d\n", pSumCnt(N, 0, K));
	}
}