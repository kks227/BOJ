#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_P = 1000000;

int main(){
	int K, cnt = 0;
	scanf("%d", &K);
	bool np[MAX_P+1] = {1, 1,};
	while(K%2 == 0){
		K /= 2;
		cnt++;
	}
	for(int i=3; i<MAX_P; i+=2){
		if(np[i]) continue;
		while(K%i == 0){
			K /= i;
			cnt++;
		}
		for(long long j=1LL*i*i; j<MAX_P; j+=i*2) np[j] = true;
	}

	int temp = 1, result = 0;
	while(1){
		if(temp >= cnt){
			printf("%d\n", result);
			break;
		}
		temp *= 2;
		result++;
	}
}