#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){

	int N, s[3000];
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", s+i);
	for(int i=1; i<N; i++){
		for(int j=0; j<N; j++)
			scanf("%d", s+N+j);
		sort(s, s+N*2);
		memcpy(s, s+N, sizeof(int)*N);
	}
	printf("%d\n", s[0]);

	return 0;
}