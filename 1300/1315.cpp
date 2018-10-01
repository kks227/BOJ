#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int N, S[100], I[100], P[100], dp[1001][1001];
bool visited[100];

int rpg(int s, int i){
	int &ret = dp[s][i];
	if(ret != -1) return ret;

	ret = 0;
	int pnt = 0;
	vector<int> newQuest;
	for(int q=0; q<N; q++){
		if(S[q] <= s || I[q] <= i){
			ret++;
			if(!visited[q]){
				visited[q] = true;
				pnt += P[q];
				newQuest.push_back(q);
			}
		}
	}
	for(int p=0; p<=pnt; p++)
		ret = max(rpg(min(s+p, 1000), min(i+pnt-p, 1000)), ret);
	for(int q: newQuest)
		visited[q] = false;
	return ret;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d %d %d", S+i, I+i, P+i);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", rpg(1, 1));
}