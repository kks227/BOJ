#include <cstdio>
#include <algorithm>
using namespace std;

const int UNDEF = 0x7FFFFFFF, IMPOSSIBLE = -1000000;
int N, val[2][400], cnt[2], cache[400][400][400];

int maxCost(int pos, int upper, int lower){
	if(N-pos < max(upper, lower)) return IMPOSSIBLE;
	if(upper==0 || lower==0) return 0;
	int &ret = cache[pos][upper][lower];
	if(ret != UNDEF) return ret;
	ret = IMPOSSIBLE;
	int temp = maxCost(pos+1, upper-1, lower-1);
	if(temp != IMPOSSIBLE) ret = temp + val[0][upper-1]*val[1][lower-1];
	temp = maxCost(pos+1, upper, lower-1);
	if(temp != IMPOSSIBLE) ret = max(ret, temp);
	temp = maxCost(pos+1, upper-1, lower);
	if(temp != IMPOSSIBLE) ret = max(ret, temp);
	return ret;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<2; i++)
		for(int j=0; j<N; j++){
			int n;
			scanf("%d", &n);
			if(n) val[i][cnt[i]++] = n;
		}
	for(int i=0; i<400; i++)
		for(int j=0; j<400; j++)
			for(int k=0; k<400; k++)
				cache[i][j][k] = UNDEF;
	printf("%d\n", maxCost(0, cnt[0], cnt[1]));
}