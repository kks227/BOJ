#include <cstdio>
#include <cstring>
using namespace std;

int dp[21][21][21];

int w(int a, int b, int c){
	if(a<=0 || b<=0 || c<=0) return 1;
	if(a>20 || b>20 || c>20) return w(20, 20, 20);
	int &ret = dp[a][b][c];
	if(ret != -1) return ret;
	if(a<b && b<c) return ret = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
	else return ret = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
}

int main(){
	memset(dp, -1, sizeof(dp));
	while(1){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if(a==-1 && b==-1 && c==-1) break;
		printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
	}
}