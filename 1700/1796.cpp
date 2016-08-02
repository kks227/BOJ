#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int L[26], R[26], cnt[26], nextC[26], dp[27][2];

int keyboard(int c, bool onRight){
	int &ret = dp[c][onRight];
	if(ret != -1) return ret;
	if(nextC[c] == 26) return ret = R[c]-L[c]+cnt[c];

	int nc = nextC[c];
	if(onRight)
		ret = min(keyboard(nc, false) + abs(L[nc]-L[c]), keyboard(nc, true) + abs(R[nc]-L[c]));
	else
		ret = min(keyboard(nc, true) + abs(R[nc]-R[c]), keyboard(nc, false) + abs(L[nc]-R[c]));
	return ret += R[c]-L[c]+cnt[c];
}

int main(){
	int i = 0, s = 26; // s: 등장하는 가장 사전순 앞 알파벳
	fill(L, L+26, -1);
	while(1){
		char c = getchar();
		if(c == '\n') break;
		c -= 'a';
		if(L[c] == -1) L[c] = i;
		R[c] = i;
		cnt[c]++;
		s = min(s, (int)c);
		i++;
	}

	for(int i=s; i<26;){
		int next = i+1;
		for(; next<26 && cnt[next]==0; next++);
		nextC[i] = next;
		i = next;
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", min(keyboard(s, false)+L[s], keyboard(s, true)+R[s]));
}