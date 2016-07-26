#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int val[120], dp[300001];

int minTetrahedron(int n){
	if(n == 0) return 0;
	int &ret = dp[n];
	if(ret != -1) return ret;

	ret = n;
	for(int i=0; n>=val[i]; i++)
		ret = min(ret, minTetrahedron(n-val[i]) + 1);
	return ret;
}

int main(){
	val[0] = 1;
	for(int i=1; i<120; i++)
		val[i] = val[i-1] + (i+1)*(i+2)/2;
	int N;
	scanf("%d", &N);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", minTetrahedron(N));
}