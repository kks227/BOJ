#include <cstdio>
#include <cstring>
using namespace std;

int L;
char S[201], dp[201][101][3];

// predecessor: 0-opening parenthesis, 1-element, 2-comma
char kindergarten(int pos, int opened, int pre){
	char &ret = dp[pos][opened][pre];
	if(ret != -1) return ret;
	if(pos == L) return ret = !opened && pre != 2;
	if(L-pos < opened) return ret = false;

	ret = false;
	if(pre == 0){
		if(S[pos] == '{')
			ret |= kindergarten(pos+1, opened+1, 0);
		if(S[pos] == '}' && opened > 0)
			ret |= kindergarten(pos+1, opened-1, 1);
		ret |= kindergarten(pos+1, opened, 1);
	}
	else if(pre == 1){
		if(S[pos] == '}' && opened > 0)
			ret |= kindergarten(pos+1, opened-1, 1);
		if(S[pos] == ',')
			ret |= kindergarten(pos+1, opened, 2);
	}
	else{
		if(S[pos] == '{')
			ret |= kindergarten(pos+1, opened+1, 0);
		ret |= kindergarten(pos+1, opened, 1);
	}
	return ret;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++){
		scanf("%s", S);
		L = strlen(S);
		memset(dp, -1, sizeof(dp));
		bool result = (S[0] == '{' && S[--L] == '}');
		if(result) result = kindergarten(1, 0, 0);
		printf("Word #%d: %sSet\n", t, result ? "" : "No ");
	}
}