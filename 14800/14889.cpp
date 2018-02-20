#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int N, cnt, S[20][20], result = INF;
bool team[20];

void dfs(int pos = 0){
	if(cnt == N/2 || cnt+N/2 == pos){
		int a[2] = {0};
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				if(i != j && team[i] == team[j]) a[team[i]] += S[i][j];
		result = min(abs(a[0]-a[1]), result);
		return;
	}

	dfs(pos+1);
	team[pos] = true; cnt++;
	dfs(pos+1);
	team[pos] = false; cnt--;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			scanf("%d", &S[i][j]);
	dfs();
	printf("%d\n", result);
}