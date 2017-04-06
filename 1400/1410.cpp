#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MOD = 1000003;

int N, K, L, dp[1<<15][51];
char P[15][51];

int cnt(int invalid, int pos){
	int &ret = dp[invalid][pos];
	if(ret != -1) return ret;

	vector<char> exist;
	int ni = 0;
	int vcnt = N;
	for(int i=0; i<N; i++){
		if(invalid & 1<<i) vcnt--;
		else if(P[i][pos] != '?'){
			exist.push_back(P[i][pos]);
			ni |= 1 << i;
		}
	}
	if(pos == L) return ret = (vcnt == K);
	else if(vcnt < K) return ret = 0;
	ret = 0;
	
	sort(exist.begin(), exist.end());
	int u = unique(exist.begin(), exist.end()) - exist.begin();
	for(int i=0; i<u; i++){
		int tv = 0;
		for(int j=0; j<N; j++){
			if(invalid & 1<<j) continue;
			if(P[j][pos] == exist[i]) tv |= 1<<j;
		}
		ret = (cnt(invalid | (ni-tv), pos+1) + ret) % MOD;
	}
	ret = (cnt(invalid | ni, pos+1)*(26-u) + ret) % MOD;
	return ret;
}

int main(){
	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++)
		scanf("%s", P[i]);
	L = strlen(P[0]);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", cnt(0, 0));
}