#include <cstdio>
#include <cstring>
using namespace std;

#define MODULA 100000LL

int N, dp[201][201];
char S[201];
bool over[201][201], zero[201][201];
const int MOD = 100000;

int paren(int start, int end){
	int &ret = dp[start][end];
	if(ret != -1) return ret;
	if(start == end) return ret = 1;
	if((end-start)%2){
		zero[start][end] = true;
		return ret = 0;
	}

	ret = 0;
	for(int i=start+1; i<end; i+=2){
		int c = 0;
		if(S[start] == '('){
			if(S[i] == ')' || S[i] == '?') c = 1;
		}
		else if(S[start] == '{'){
			if(S[i] == '}' || S[i] == '?') c = 1;
		}
		else if(S[start] == '['){
			if(S[i] == ']' || S[i] == '?') c = 1;
		}
		else if(S[start] == '?'){
			if(S[i] == ')' || S[i] == '}' || S[i] == ']') c = 1;
			else if(S[i] == '?') c = 3;
		}
		//else: ) } ]

		if(c > 0){
			ret += 1LL * c * paren(start+1, i) * paren(i+1, end) % MOD;
			if( (over[start+1][i] || over[i+1][end]) && !zero[start+1][i] && !zero[i+1][end] ) over[start][end] = true;
		}
	}
	if(ret >= MOD) over[start][end] = true;
	if(!over[start][end] && ret == 0) zero[start][end] = true;
	return ret %= MOD;
}

int main(){
	scanf("%d %s", &N, S);
	memset(dp, -1, sizeof(dp));
	int result = paren(0, N);
	printf(over[0][N]?"%05d\n":"%d\n", result);
}