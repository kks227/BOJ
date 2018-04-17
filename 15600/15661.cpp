#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int N, S[20][20], result = 1e9, cnt;
bool team[20];

void dfs(int pos = 0){
	if(pos == N){
		if(cnt > 0 && cnt < N){
			int temp[2] = {0};
			for(int i=0; i<N; i++)
				for(int j=0; j<N; j++)
					if(team[i] == team[j]) temp[team[i]] += S[i][j];
			result = min(abs(temp[0]-temp[1]), result);
		}
		return;
	}

	dfs(pos+1);
	team[pos] = true;
	cnt++;
	dfs(pos+1);
	team[pos] = false;
	cnt--;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			scanf("%d", &S[i][j]);
	dfs();
	printf("%d\n", result);
}