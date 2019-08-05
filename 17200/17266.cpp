#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 100000;

int main(){
	int N, M, x[MAX];
	scanf("%d %d", &N, &M);
	for(int i = 0; i < M; ++i)
		scanf("%d", x+i);
	int temp = max(x[0]*2, (N-x[M-1])*2);
	for(int i = 1; i < M; ++i)
		temp = max(x[i]-x[i-1], temp);
	printf("%d\n", (temp+1)/2);
}