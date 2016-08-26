#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int IMPOSSIBLE = 1000000000;

int N, Slen, len[50], dp[51];
char S[51], W[50][51];

int secret(int pos){
	int &ret = dp[pos];
	if(ret != -1) return ret;
	if(pos == Slen) return ret = 0;

	ret = IMPOSSIBLE;
	for(int i=0; i<N; i++){
		if(pos+len[i] <= Slen){
			int cost = 0, cnt[26] = {0};
			for(int j=0; j<len[i]; j++){
				if(S[pos+j] != W[i][j]) cost++;
				cnt[S[pos+j]-'a']++;
				cnt[W[i][j]-'a']--;
			}
			bool possible = true;
			for(int j=0; j<26; j++){
				if(cnt[j] != 0){
					possible = false;
					break;
				}
			}
			if(possible) ret = min(ret, secret(pos+len[i])+cost);
		}
	}
	return ret;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		scanf("%s %d", S, &N);
		Slen = strlen(S);
		for(int i=0; i<N; i++){
			scanf("%s", W[i]);
			len[i] = strlen(W[i]);
		}
		memset(dp, -1, sizeof(dp));
		int result = secret(0);
		printf("%d\n", result != IMPOSSIBLE ? result : -1);
	}
}