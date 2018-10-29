#include <cstdio>
#include <cstring>
using namespace std;

int N;
bool S[150];
char dp[151][2][6];

bool submarine(int pos, int s, int ss){
	char &ret = dp[pos][s][ss];
	if(ret != -1) return ret;
	if(pos == N) return ret = (!ss && pos > 0);

	ret = false;
	if(s == 0){
		if(ss == 0){ // '1'
			if(S[pos]) ret = submarine(pos+1, s, 1);
		}
		else if(ss == 1){ // '0'
			if(!S[pos]) ret = submarine(pos+1, s, 2);
		}
		else if(ss == 2){ // '0'
			if(!S[pos]) ret = submarine(pos+1, s, 3);
			else ret = submarine(pos+1, s, 4);
		}
		else if(ss == 3){ // '0'*
			if(!S[pos]) ret = submarine(pos+1, s, 3);
			else ret = submarine(pos, s, 4);
		}
		else if(ss == 4){ // '1'
			if(S[pos]) ret = submarine(pos+1, s, 5);
			ret |= submarine(pos+1, !S[pos+1], 0);
		}
		else{ // '1'*
			if(S[pos]) ret = submarine(pos+1, s, 5);
			ret |= submarine(pos, !S[pos], 0);
		}
	}
	else{
		if(ss == 0 && !S[pos])
			ret = submarine(pos+1, s, 1);
		else if(ss == 1 && S[pos])
			ret = submarine(pos+1, !S[pos+1], 0);
	}
	return ret;
}

int main(){
	while(1){
		char c = getchar();
		if(c == '\n') break;
		S[N++] = c-'0';
	}
	memset(dp, -1, sizeof(dp));
	puts(submarine(0, !S[0], 0) ? "SUBMARINE" : "NOISE");
}