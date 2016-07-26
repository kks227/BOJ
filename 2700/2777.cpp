#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){

	int T, N;
	scanf("%d", &T);
	int prime[4] = {2, 3, 5, 7};
	int cnt[4], result;
	for(int i=0; i<T; i++){
		scanf("%d", &N);
		if(N == 1){
			printf("1\n");
			continue;
		}
		memset(cnt, 0, sizeof(int)*4);
		for(int j=0; j<4; j++){
			while(N%prime[j] == 0){
				cnt[j]++;
				N /= prime[j];
			}
		}
		if(N != 1){
			printf("-1\n");
			continue;
		}

		result = 0;
		if(cnt[0] >= 3){
			result += cnt[0]/3;
			cnt[0] %= 3;
		}
		if(cnt[1] >= 2){
			result += cnt[1]/2;
			cnt[1] %= 2;
		}
		if(cnt[0] && cnt[1]){
			cnt[0]--;
			cnt[1]--;
			result++;
		}
		if(cnt[0]) result++;
		if(cnt[1]) result++;
		result += cnt[2] + cnt[3];
		printf("%d\n", result);
	}

	return 0;
}