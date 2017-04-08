#include <cstdio>
#include <algorithm>
using namespace std;

int N, M, map[4][4], rowspan[4][4], colspan[4][4], result;
bool used[4][4];

void dfs(){
	int r = -1, c = -1, sum = 0;
	for(int k=0; k<N*M; k++){
		if(!used[k/M][k%M]){
			r = k/M;
			c = k%M;
			break;
		}
	}
	if(r == -1){
		int sum = 0;
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				if(rowspan[i][j] > 0){
					int temp = 0;
					for(int k=0; k<rowspan[i][j]; k++)
						temp = temp*10 + map[i+k][j];
					sum += temp;
				}
				else if(colspan[i][j] > 0){
					int temp = 0;
					for(int k=0; k<colspan[i][j]; k++)
						temp = temp*10 + map[i][j+k];
					sum += temp;
				}
			}
		}
		result = max(result, sum);
		return;
	}

	int l = 0;
	for(int k=0; r+k<N && !used[r+k][c]; k++, l++){
		rowspan[r][c] = k+1;
		used[r+k][c] = true;
		dfs();
	}
	rowspan[r][c] = 0;
	for(int k=1; k<l; k++)
		used[r+k][c] = false;

	l = 1;
	for(int k=1; c+k<M && !used[r][c+k]; k++, l++){
		colspan[r][c] = k+1;
		used[r][c+k] = true;
		dfs();
	}
	colspan[r][c] = 0;
	for(int k=0; k<l; k++)
		used[r][c+k] = false;
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			scanf("%1d", &map[i][j]);
	dfs();
	printf("%d\n", result);
}