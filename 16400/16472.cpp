#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
	int N, L;
	char S[100001];
	scanf("%d %s", &N, S);
	L = strlen(S);

	int lo = 0, hi = 0, acnt = 0, cnt[26] = {0,}, result = 0;
	while(lo < L){
		while(hi < L && acnt <= N){
			if(cnt[S[hi++]-'a']++ == 0 && ++acnt > N) break;
			result = max(hi-lo, result);
		}
		while(--cnt[S[lo++]-'a'] > 0 || --acnt > N);
	}
	printf("%d\n", result);
}