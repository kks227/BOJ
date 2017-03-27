#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, A[8], p[8];
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", A+i);
		p[i] = i;
	}
	int result = 0;
	do{
		int cnt = 0, sum = 0;
		bool used[101] = {0};
		for(int i=0; i<N; i++){
			sum += A[p[i]];
			if(sum >= 50 && used[sum-50]) cnt++;
			used[sum] = true;
		}
		result = max(result, cnt);
	}while(next_permutation(p, p+N));
	printf("%d\n", result);
}