#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
	int N, M, x[100000], y[100000], result = 0;
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++)
		scanf("%d %d", x+i, y+i);
	sort(x, x+M);
	sort(y, y+M);
	for(int i=0; i<M; i++)
		result += abs(x[i]-x[M/2]) + abs(y[i]-y[M/2]);
	printf("%d\n", result);
}