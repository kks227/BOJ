#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int INF = 1000000000;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int main(){
	int N, M, T, D, H[25][25], W[625][625];
	scanf("%d %d %d %d\n", &N, &M, &T, &D);
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			char c = getchar();
			if(c <= 'Z') H[i][j] = c-'A';
			else H[i][j] = c-'a'+26;
		}
		getchar();
	}

	for(int i=0; i<N*M; i++)
		for(int j=0; j<N*M; j++)
			W[i][j] = (i==j ? 0 : INF);
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			for(int d=0; d<4; d++){
				int ni = i+roff[d];
				int nj = j+coff[d];
				if(ni<0 || ni>=N || nj<0 || nj>=M) continue;

				int diff = H[ni][nj] - H[i][j];
				if(abs(diff) > T) continue;
				if(diff <= 0) W[i*M+j][ni*M+nj] = 1;
				else W[i*M+j][ni*M+nj] = diff*diff;
			}

	for(int k=0; k<N*M; k++)
		for(int i=0; i<N*M; i++)
			for(int j=0; j<N*M; j++)
				W[i][j] = min(W[i][j], W[i][k]+W[k][j]);

	int result = 0;
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			if(W[0][i*M+j]+W[i*M+j][0] <= D)
				result = max(result, H[i][j]);
	printf("%d\n", result);
}