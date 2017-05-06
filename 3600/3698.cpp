#include <cstdio>
#include <cstring>
using namespace std;

char S[1001], W[10000][101];
int L, N, WL[10000], dp[10001], track[10001];

int ambiguous(int pos){
	int &ret = dp[pos];
	if(ret != -1) return ret;
	if(pos == L) return ret = 1;

	ret = 0;
	for(int i=0; i<N; i++){
		if(L-pos < WL[i] || S[pos] != W[i][0] || S[pos+WL[i]-1] != W[i][WL[i]-1]) continue;
		int cnt[26] = {0};
		for(int j=1; j<WL[i]-1; j++){
			cnt[S[pos+j]-'a']++;
			cnt[W[i][j]-'a']--;
		}
		bool same = true;
		for(int j=0; j<26; j++){
			if(cnt[j]){
				same = false;
				break;
			}
		}
		if(same && ambiguous(pos+WL[i])){
			ret += ambiguous(pos+WL[i]);
			track[pos] = i;
		}
	}
	return ret;
}

void trace(int pos){
	if(pos == L){
		puts("");
		return;
	}
	printf("%s ", W[track[pos]]);
	trace(pos+WL[track[pos]]);
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		scanf("%s %d", S, &N);
		L = strlen(S);
		for(int i=0; i<N; i++){
			scanf("%s", W[i]);
			WL[i] = strlen(W[i]);
		}
		memset(track, -1, sizeof(track));
		memset(dp, -1, sizeof(dp));

		switch(ambiguous(0)){
			case 0: puts("impossible"); break;
			case 1: trace(0); break;
			default: puts("ambiguous"); break;
		}
	}
}