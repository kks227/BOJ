#include <cstdio>
#include <cstring>
using namespace std;

char S[101];
long long dp[101][2][3][2];

inline bool isVowel(char c){
	return (c=='A' || c=='E' || c=='I' || c=='O' || c=='U');
}

long long happy(int pos, bool vowel, int seq, bool L){
	long long &ret = dp[pos][vowel][seq][L];
	if(ret != -1) return ret;
	if(!S[pos]) return ret = L;

	ret = 0;
	if(S[pos] == '_'){
		if(vowel){
			ret += happy(pos+1, false, 1, L)*20 + happy(pos+1, false, 1, true);
			if(seq < 2) ret += happy(pos+1, true, seq+1, L)*5;
		}
		else{
			ret += happy(pos+1, true, 1, L)*5;
			if(seq < 2) ret += happy(pos+1, false, seq+1, L)*20 + happy(pos+1, false, seq+1, true);
		}
	}
	else{
		if(S[pos] == 'L') L = true;
		if(isVowel(S[pos])){
			if(!vowel) ret += happy(pos+1, true, 1, L);
			else if(seq < 2) ret += happy(pos+1, true, seq+1, L);
		}
		else{
			if(vowel) ret += happy(pos+1, false, 1, L);
			else if(seq < 2) ret += happy(pos+1, false, seq+1, L);
		}
	}
	return ret;
}

int main(){
	scanf("%s", S);
	memset(dp, -1, sizeof(dp));
	printf("%lld\n", happy(0, 0, 0, 0));
}