#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int N, result = INF;
bool coin[20][20], r[20];

void dfs(int pos){
	if(pos == N){
		int sum = 0;
		for(int c=0; c<N; c++){
			int cnt = 0;
			for(int k=0; k<N; k++)
				if(coin[k][c] != r[k]) cnt++;
			sum += min(cnt, N-cnt);
		}
		result = min(result, sum);
		return;
	}
	dfs(pos+1);
	r[pos] = true;
	dfs(pos+1);
	r[pos] = false;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		getchar();
		for(int j=0; j<N; j++)
			coin[i][j] = (getchar() == 'T');
	}
	dfs(0);
	printf("%d\n", result);
}