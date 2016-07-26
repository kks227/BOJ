#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int N, W, x[1000], y[1000], cache[1001][1001];
bool choose[1001][1001];

int minSum(int s1, int s2){
	int current = max(s1, s2);
	if(current == W) return 0;
	int &ret = cache[s1][s2];
	if(ret != -1) return ret;
	int c1 = minSum(current+1, s2) + (s1==0 ? x[current]+y[current] : abs(x[current]-x[s1-1])+abs(y[current]-y[s1-1]));
	int c2 = minSum(s1, current+1) + (s2==0 ? N*2-x[current]-y[current] : abs(x[current]-x[s2-1])+abs(y[current]-y[s2-1]));
	choose[s1][s2] = c1>c2;
	return ret = min(c1, c2);
}

void printCarNumber(int s1, int s2){
	int current = max(s1, s2);
	if(current == W) return;
	printf("%d\n", choose[s1][s2]+1);
	if(choose[s1][s2]) printCarNumber(s1, current+1);
	else printCarNumber(current+1, s2);
}

int main(){
	scanf("%d %d", &N, &W);
	N--;
	for(int i=0; i<W; i++){
		scanf("%d %d", x+i, y+i);
		x[i]--; y[i]--;
	}
	memset(cache, -1, sizeof(cache));
	printf("%d\n", minSum(0, 0));
	printCarNumber(0, 0);
}