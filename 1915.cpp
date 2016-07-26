#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, dp1[1000][1000], dp2[1000][1000];
bool map[1000][1000];

int largest1(int r, int c);
int largest2(int r, int c);

int main(){
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			scanf("%1d", &map[i][j]);
	memset(dp1, -1, sizeof(dp1));
	memset(dp2, -1, sizeof(dp2));
	printf("%d\n", largest2(N-1, M-1)*largest2(N-1, M-1));
}

int largest1(int r, int c){
	if(r==-1 || c==-1) return 0;
	int &ret = dp1[r][c];
	if(ret != -1) return ret;
	if(!map[r][c]) return ret = 0;
	ret = 1;
	int temp = min(largest1(r-1, c), largest1(r, c-1));
	if(map[r-temp][c-temp]) ret = temp+1;
	else ret = temp;
	return ret;
}

int largest2(int r, int c){
	if(r==-1 || c==-1) return 0;
	int &ret = dp2[r][c];
	if(ret != -1) return ret;
	return ret = max(largest1(r, c), max(largest2(r-1, c), largest2(r, c-1)));
}