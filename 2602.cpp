#include <cstdio>
#include <cstring>
using namespace std;

char roll[21], angel[101], devil[101];
int rLen, bLen, dp[100][2][20];

int cntCrossing(int bPos, bool onA, int rPos){
	if(rPos == rLen) return 1;
	if(bPos == bLen) return 0;
	int &ret = dp[bPos][onA][rPos];
	if(ret != -1) return ret;

	ret = 0;
	char *b = (onA ? devil : angel);
	for(int i=bPos; i<bLen; i++)
		if(roll[rPos] == b[i]) ret += cntCrossing(i+1, !onA, rPos+1);
	return ret;
}

int main(){
	scanf("%s %s %s", roll, angel, devil);
	rLen = strlen(roll);
	bLen = strlen(angel);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", cntCrossing(0, false, 0) + cntCrossing(0, true, 0));
}