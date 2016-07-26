#include <cstdio>
#include <algorithm>
using namespace std;

int main(){

	int n;
	long long len[3];
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%lld %lld %lld", &len[0], &len[1], &len[2]);
		sort(len, len+3);
		printf("Scenario #%d:\n", i);
		if(len[2]*len[2] == len[0]*len[0]+len[1]*len[1]) printf("yes\n");
		else printf("no\n");
		if(i<n) printf("\n");
	}

    return 0;
}