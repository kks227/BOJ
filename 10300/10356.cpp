#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
#include <utility>
using namespace std;
typedef pair<int, int> P;

char x[1001];
vector<P> n[26];
bool t[26][26];
char dp[1001][1001][26];

bool CYK(int s, int e, int curr){
	char &ret = dp[s][e][curr];
	if(ret != -1) return ret;
	if(s+1 == e) return ret = t[curr][x[s]-'a'];

	for(int i = s+1; i < e; ++i)
		for(auto &p: n[curr])
			if(CYK(s, i, p.first) && CYK(i, e, p.second)) return ret = true;
	return ret = false;
}

int main(){
	scanf("%s", x);
	char R[4];
	while(scanf("%s", R) > 0){
		if(R[2] == '\0') t[R[0]-'A'][R[1]-'a'] = true;
		else n[R[0]-'A'].push_back(P(R[1]-'A', R[2]-'A'));
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", CYK(0, strlen(x), 'S'-'A'));
}