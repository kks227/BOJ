#include <cstdio>
using namespace std;

inline long long sum(int N){
	return 1LL*N*(N+1)/2;
}

int main(){
	int N, K, R=0, C=0;
	long long result = 1;
	scanf("%d %d\n", &N, &K);
	for(int i=0; i<K; i++){
		switch(getchar()){
		case 'U':
			R--;
			break;
		case 'D':
			R++;
			break;
		case 'L':
			C--;
			break;
		default:
			C++;
		}
		if(R+C < N) result += sum(R+C) + ((R+C)%2?R:C)+1;
		else result += sum(N) + sum(N-1) - sum(2*N-(R+C+1)) + ((R+C)%2?R:C)-(R+C-N);
	}
	printf("%lld\n", result);
}