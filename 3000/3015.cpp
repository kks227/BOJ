#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, S[500000];
	long long result = 0;
	scanf("%d", &N);
	int top = N;
	for(int i=0; i<N; i++){
		int H;
		scanf("%d", &H);
		while(top<N && S[top]<H){
			result++;
			top++;
		}
		if(top < N){
			int lo = lower_bound(S+top, S+N, H)-S;
			int hi = upper_bound(S+top, S+N, H)-S;
			if(lo<hi) result += hi-lo + (hi<N);
			else result++;
		}
		S[--top] = H;
	}
	printf("%lld\n", result);
}