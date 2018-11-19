#include <cstdio>
#include <algorithm>
using namespace std;
int INF = 1e9;

int N, cost[16], cnt[26], bcnt[16][26], result = INF, sum;
bool used[16];

void backtrack(int pos){
	if(pos == N){
		int temp[26] = {0};
		for(int i = 0; i < N; ++i){
			if(!used[i]) continue;
			for(int j = 0; j < 26; ++j)
				temp[j] += bcnt[i][j];
		}
		for(int i = 0; i < 26; ++i)
			if(temp[i] < cnt[i]) return;
		result = min(sum, result);
		return;
	}

	backtrack(pos+1);
	used[pos] = true;
	sum += cost[pos];
	backtrack(pos+1);
	used[pos] = false;
	sum -= cost[pos];
}

int main(){
	char S[51];
	scanf("%s %d", S, &N);
	for(int i = 0; S[i]; ++i)
		++cnt[S[i]-'A'];
	for(int i = 0; i < N; ++i){
		scanf("%d %s", cost+i, S);
		for(int j = 0; S[j]; ++j)
			++bcnt[i][S[j]-'A'];
	}
	backtrack(0);
	if(result == INF) result = -1;
	printf("%d\n", result);
}