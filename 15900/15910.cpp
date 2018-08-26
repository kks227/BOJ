#include <cstdio>
#include <cstring>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int IMPOSSIBLE = 1e9;

unordered_map<char, int> C2N;
char S[100001];
int dp[100001][7], go[7][3] = {
	-1, 1, -1,
	2, 1, -1,
	-1, -1, 3,
	4, -1, -1,
	-1, -1, 5,
	6, -1, -1,
	-1, 1, 5
};

int banana(int pos, int state){
	int &ret = dp[pos][state];
	if(ret != -1) return ret;
	if(S[pos] == '\0') return ret = (state == 6 ? 0 : IMPOSSIBLE);

	ret = IMPOSSIBLE;
	if(state == 6) ret = banana(pos, 0);
	int k = C2N[S[pos]];
	for(int i=0; i<3; i++){
		if(go[state][i] < 0) continue;
		ret = min(banana(pos+1, go[state][i]) + (k != i), ret);
	}
	return ret;
}

int main(){
	C2N['A'] = 0;
	C2N['B'] = 1;
	C2N['N'] = 2;
	scanf("%s", S);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", banana(0, 0));
}