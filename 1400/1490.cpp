#include <cstdio>
#include <set>
using namespace std;

int main(){
	int N, K;
	set<int> D;
	scanf("%d", &N);
	K = N;
	while(N > 0){
		if(N%10 > 1) D.insert(N%10);
		N /= 10;
	}
	for(int p10=1; ; p10*=10){
		for(int i=0; i<p10; i++){
			long long M = 1LL*K*p10 + i;
			bool flag = true;
			for(int d: D){
				if(M%d != 0){
					flag = false;
					break;
				}
			}
			if(flag){
				printf("%lld\n", M);
				return 0;
			}
		}
	}
}