#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int IMPOSSIBLE = -1e9;

int N, H[50], dp[51][500001];

int tower(int pos, int diff){
	int &ret = dp[pos][diff];
	if(ret != -1) return ret;
	if(pos == N) return ret = (diff ? IMPOSSIBLE : 0);

	ret = tower(pos+1, diff);
	ret = max(ret, tower(pos+1, diff+H[pos]));
	if(diff >= H[pos])
		ret = max(ret, tower(pos+1, diff-H[pos]) + H[pos]);
	else
		ret = max(ret, tower(pos+1, H[pos]-diff) + diff);
	return ret;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", H+i);

	memset(dp, -1, sizeof(dp));
	int result = tower(0, 0);
	if(result == IMPOSSIBLE || result == 0) result = -1;
	printf("%d\n", result);
}