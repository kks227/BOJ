#include <cstdio>
#include <algorithm>
using namespace std;
const int roff[5] = {0, -1, 1, 0, 0};
const int coff[5] = {0, 0, 0, -1, 1};
const int INF = 1e9;

int N, G[10][10], sum, result = INF;
bool used[10][10];

void dfs(int planted){
	if(planted == 3){
		result = min(result, sum);
		return;
	}
	for(int r=1; r<N-1; r++){
		for(int c=1; c<N-1; c++){
			bool possible = true;
			for(int d=0; d<5; d++)
				if(used[r+roff[d]][c+coff[d]]) possible = false;
			if(!possible) break;
			for(int d=0; d<5; d++){
				sum += G[r+roff[d]][c+coff[d]];
				used[r+roff[d]][c+coff[d]] = true;
			}
			dfs(planted+1);
			for(int d=0; d<5; d++){
				sum -= G[r+roff[d]][c+coff[d]];
				used[r+roff[d]][c+coff[d]] = false;
			}
		}
	}
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			scanf("%d", &G[i][j]);
	dfs(0);
	printf("%d\n", result);
}