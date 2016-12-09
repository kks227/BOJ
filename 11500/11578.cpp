#include <cstdio>
#include <algorithm>
using namespace std;

int N, M, O[10], P[10][10], result = 11;
bool team[10];

void dfs(int n){
	if(n == M){
		int cnt = 0;
		bool solve[10] = {0};
		for(int i=0; i<M; i++){
			if(!team[i]) continue;
			cnt++;
			for(int j=0; j<O[i]; j++)
				solve[P[i][j]] = true;
		}
		bool success = true;
		for(int i=0; i<N; i++){
			if(!solve[i]){
				success = false;
				break;
			}
		}
		if(success) result = min(result, cnt);
		return;
	}

	dfs(n+1);
	team[n] = true;
	dfs(n+1);
	team[n] = false;
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		scanf("%d", O+i);
		for(int j=0; j<O[i]; j++){
			scanf("%d", &P[i][j]);
			P[i][j]--;
		}
	}

	dfs(0);
	if(result == 11) result = -1;
	printf("%d\n", result);
}