#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x80000000;

char X[3001], Y[3001];
int Xlen, Ylen, A, B, C, dp[3001][3001];

int maxScore(int Xpos, int Ypos){
	int &ret = dp[Xpos][Ypos];
	if(ret != INF) return ret;
	if(Xpos == Xlen) return ret = (Ylen-Ypos)*B;
	if(Ypos == Ylen) return ret = (Xlen-Xpos)*B;

	ret = max(maxScore(Xpos+1, Ypos)+B, maxScore(Xpos, Ypos+1)+B);
	ret = max(ret, maxScore(Xpos+1, Ypos+1)+C);
	if(X[Xpos] == Y[Ypos]) ret = max(ret, maxScore(Xpos+1, Ypos+1)+A);
	return ret;
}

int main(){
	scanf("%d %d %d %s %s", &A, &B, &C, X, Y);
	Xlen = strlen(X);
	Ylen = strlen(Y);
	for(int i=0; i<3001; i++)
		for(int j=0; j<3001; j++)
			dp[i][j] = INF;
	printf("%d\n", maxScore(0, 0));
}