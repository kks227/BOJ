#include <cstdio>
using namespace std;

int main(){
	int N, K, p = 1, cnt = 1;
	scanf("%d %d", &N, &K);
	K--;
	bool lessDigits = false;
	while(N >= p*10LL){
		if(K < p*9LL*cnt){
			lessDigits = true;
			break;
		}
		K -= p*9LL*cnt;
		cnt++;
		p *= 10;
	}

	int q = K/cnt + p;
	if(!lessDigits && q > N%(p*10LL)) puts("-1");
	else{
		int r = K%cnt;
		for(int i=0; i<cnt-r-1; i++) q /= 10;
		printf("%d\n", q%10);
	}
}