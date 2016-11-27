#include <cstdio>
#include <cstring>
using namespace std;
const int roff[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int coff[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int H, W, L;
char word[101], map[200][201];
long long dp[200][200][101];

long long grid(int r, int c, int k){
	long long &ret = dp[r][c][k];
	if(ret != -1) return ret;
	if(k == L) return ret = 1;

	ret = 0;
	for(int d=0; d<8; d++){
		int nr = r+roff[d], nc = c+coff[d];
		if(nr<0 || nr>=H || nc<0 || nc>=W) continue;
		if(map[nr][nc] == word[k]) ret += grid(nr, nc, k+1);
	}
	return ret;
}

int main(){
	scanf("%d %d %d", &H, &W, &L);
	for(int i=0; i<H; i++)
		scanf("%s", map[i]);
	scanf("%s", word);
	
	memset(dp, -1, sizeof(dp));
	long long result = 0;
	for(int i=0; i<H; i++)
		for(int j=0; j<W; j++)
			if(map[i][j] == word[0]) result += grid(i, j, 1);
	printf("%lld\n", result);
}