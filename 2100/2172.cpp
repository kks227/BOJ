#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

int N, L, map[20][20], dp[20][20][20][20][10];
const int roff[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int coff[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int INF = 0x7FFFFFFF;

inline bool invalid(int r, int c){
	return r<0 || r>=N || c<0 || c>=N;
}

void lexicog(int &r1, int &c1, int &r2, int &c2){
	if(P(r1, c1) > P(r2, c2)){
		swap(r1, r2);
		swap(c1, c2);
	}
}

int cntPals(int r1, int c1, int r2, int c2, int left){
	if(left == 0) return 1;
	lexicog(r1, c1, r2, c2);
	int &ret = dp[r1][c1][r2][c2][left];
	if(ret != -1) return ret;

	ret = 0;
	for(int d1=0; d1<8; d1++){
		int nr1 = r1 + roff[d1];
		int nc1 = c1 + coff[d1];
		if(invalid(nr1, nc1)) continue;
		for(int d2=0; d2<8; d2++){
			int nr2 = r2 + roff[d2];
			int nc2 = c2 + coff[d2];
			if(!invalid(nr2, nc2) && map[nr1][nc1] == map[nr2][nc2])
				ret += cntPals(nr1, nc1, nr2, nc2, left-1);
		}
	}
	return ret;
}



int main(){
	scanf("%d %d", &N, &L);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			scanf("%d", &map[i][j]);
	memset(dp, -1, sizeof(dp));

	int result = 0;
	if(L%2){
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				result += cntPals(i, j, i, j, L/2);
	}
	else{
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				for(int d=4; d<8; d++){
					int ni = i + roff[d];
					int nj = j + coff[d];
					if(!invalid(ni, nj) && map[i][j] == map[ni][nj])
						result += cntPals(i, j, ni, nj, L/2-1) * 2;
				}
	}
	printf("%d\n", result);
}