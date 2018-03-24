#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int main(){
	int N, result = INF;
	scanf("%d", &N);
	for(int i=0; i*2<=N; i++)
		if((N-i*2)%5 == 0) result = min(i + (N-i*2)/5, result);
	if(result == INF) puts("-1");
	else printf("%d\n", result);
}