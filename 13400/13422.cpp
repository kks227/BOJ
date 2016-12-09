#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N, M, K, money[100000], sum = 0, result = 0;
		scanf("%d %d %d", &N, &M, &K);
		for(int i=0; i<N; i++){
			scanf("%d", money+i);
			if(i >= N-M) sum += money[i];
		}
		if(N == M) result = (sum < K);
		else{
			for(int i=0; i<N; i++){
				sum += money[i] - money[(i+N-M)%N];
				if(sum < K) result++;
			}
		}
		printf("%d\n", result);
	}
}