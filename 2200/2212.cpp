#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, K, pos[10000], dif[9999];
	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++)
		scanf("%d", pos+i);
	if(K >= N) puts("0");
	else{
		sort(pos, pos+N);
		for(int i=0; i<N-1; i++)
			dif[i] = pos[i+1] - pos[i];
		sort(dif, dif+N-1);
		int result = 0;
		for(int i=0; i<K-1; i++)
			result += dif[N-2-i];
		printf("%d\n", pos[N-1]-pos[0]-result);
	}
}