#include <cstdio>
using namespace std;

int main(){

	int C, N, a, b, c;
	scanf("%d", &C);
	int cnt[1001] = {0, 0}, maxCnt = 1;

	for(int i=0; i<C; i++){
		scanf("%d", &N);
		if(maxCnt < N){
			for(maxCnt++; maxCnt<=N; maxCnt++){
				cnt[maxCnt] = cnt[maxCnt-1] + 1;
				for(int k=2; k<maxCnt; k++){
					a = maxCnt;
					b = k;
					while(b){
						c = a%b;
						a = b;
						b = c;
					}
					if(a == 1) cnt[maxCnt]++;
				}
			}
			maxCnt--;
		}
		printf("%d\n", cnt[N]*2+3);
	}

	return 0;
}