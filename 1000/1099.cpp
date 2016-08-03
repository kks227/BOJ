#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int IMPOSSIBLE = 1000000000;

int N, Slen, Wlen[50], dp[51];
char S[51], W[50][51];

int unknown(int pos){
	int &ret = dp[pos];
	if(ret != -1) return ret;
	if(pos == Slen) return ret = 0;

	ret = IMPOSSIBLE;
	for(int i=0; i<N; i++){
		if(pos+Wlen[i] > Slen) continue;

		int cnt[26] = {0};
		for(int j=0; j<Wlen[i]; j++){
			cnt[S[pos+j]-'a']++;
			cnt[W[i][j]-'a']--;
		}

		bool same = true;
		for(int j=0; j<26; j++){
			if(cnt[j] != 0){
				same = false;
				break;
			}
		}
		if(!same) continue;

		int temp = 0;
		for(int j=0; j<Wlen[i]; j++)
			if(S[pos+j] != W[i][j]) temp++;
		ret = min(ret, unknown(pos+Wlen[i]) + temp);
	}
	return ret;
}

int main(){
	scanf("%s %d", S, &N);
	Slen = strlen(S);
	for(int i=0; i<N; i++){
		scanf("%s", W[i]);
		Wlen[i] = strlen(W[i]);
	}
	memset(dp, -1, sizeof(dp));
	int result = unknown(0);
	printf("%d\n", result == IMPOSSIBLE ? -1 : result);
}