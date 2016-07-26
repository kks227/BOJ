#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N;
	while(scanf("%d", &N) > 0){
		int cost[10], p = 50, q = 50, money;
		for(int i=0; i<N; i++){
			scanf("%d", cost+i);
			p = min(p, cost[i]);
			if(i > 0) q = min(q, cost[i]);
		}
		scanf("%d", &money);
		if(N == 1){
			puts("0");
			continue;
		}

		int digit = (money-q)/p+1;
		if(digit <= 0){
			puts("0");
			continue;
		}
		for(int i=digit-1; i>=0; i--){
			for(int d=N-1; d>=0; d--){
				if(money-cost[d] >= p*i){
					money -= cost[d];
					putchar(d+'0');
					break;
				}
			}
		}
		puts("");
	}
}