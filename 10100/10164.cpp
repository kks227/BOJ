#include <cstdio>
using namespace std;

int p[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

long long C(int r, int c){
	long long result = 1;
	int cnt[10] = {0}, temp, tc;
	for(int i=2; i<=r; i++){
		temp = i;
		tc = 0;
		while(temp > 1){
			if(temp%p[tc]) tc++;
			else{
				temp /= p[tc];
				cnt[tc]++;
			}
		}
	}
	for(int i=2; i<=c; i++){
		temp = i;
		tc = 0;
		while(temp > 1){
			if(temp%p[tc]) tc++;
			else{
				temp /= p[tc];
				cnt[tc]++;
			}
		}
	}
	for(int i=2; i<=r+c; i++){
		result *= i;
		for(int j=0; j<10; j++){
			while(result%p[j]==0){
				if(cnt[j] == 0) break;
				cnt[j]--;
				result /= p[j];
			}
		}
	}
	return result;
}

int main(){

	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	printf("%lld\n", K==0?C(N-1, M-1):C((K-1)/M, (K-1)%M)*C(N-1-(K-1)/M, M-1-(K-1)%M));

	return 0;
}