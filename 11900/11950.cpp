#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int IMPOSSIBLE = 1e9;

int R, C, cnt[50][3], dp[51][3][2];

int Russia(int r, int color, bool moveable){
	int &ret = dp[r][color][moveable];
	if(ret != -1) return ret;
	if(r == R) return ret = (color == 2 ? 0 : IMPOSSIBLE);

	ret = Russia(r+1, color, true);
	for(int i=0; i<3; i++)
		if(color != i) ret += cnt[r][i];
	if(moveable && color < 2) ret = min(Russia(r, color+1, false), ret);
	return ret;
}

int main(){
	scanf("%d %d", &R, &C);
	for(int i=0; i<R; i++){
		getchar();
		for(int j=0; j<C; j++){
			char c = getchar();
			if(c == 'W') cnt[i][0]++;
			else if(c == 'B') cnt[i][1]++;
			else cnt[i][2]++;
		}
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", Russia(0, 0, false));
}