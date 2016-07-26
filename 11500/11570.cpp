#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int N, db[2000], dp[2001][2001];

int dif(int a, int b){
	int &ret = dp[a][b];
	if(ret != -1) return ret;
	if(a==N || b==N) return ret = 0;

	ret = 2000000001;
	int c = max(a, b);
	ret = min(ret, dif(c+1, b) + (a>0?abs(db[c]-db[a-1]):0));
	ret = min(ret, dif(a, c+1) + (b>0?abs(db[c]-db[b-1]):0));
	return ret;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", db+i);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", dif(0, 0));
}