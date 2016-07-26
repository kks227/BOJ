#include <cstdio>
#include <algorithm>
using namespace std;

long long fact[21] = {1, 1};

void printKthPerm(long long k, bool *use, int n){
	if(n == 1){
		for(int i=0; i<20; i++)
			if(!use[i]){
				printf("%d\n", i+1);
				return;
			}
	}

	long long pivot = 0;
	int next = -1;
	for(int i=0; i<n; i++){
		for(next++; use[next]; next++);
		if(pivot<=k && k<pivot+fact[n-1]){
			printf("%d ", next+1);
			use[next] = true;
			printKthPerm(k-pivot, use, n-1);
			return;
		}
		pivot += fact[n-1];
	}
}

long long getPermNum(int *p, int n){
	if(n == 1) return 1;

	int q = 0;
	for(int i=1; i<n; i++)
		if(p[0] > p[i]) q++;
	return getPermNum(p+1, n-1) + fact[n-1]*q;
}

int main(){
	int N, Q;
	scanf("%d %d", &N, &Q);
	for(int i=2; i<=20; i++)
		fact[i] = fact[i-1] * i;
	if(Q == 1){
		long long K;
		scanf("%lld", &K);
		bool use[20] = {0};
		printKthPerm(K-1, use, N);
	}
	else{
		int P[20];
		for(int i=0; i<N; i++)
			scanf("%d", P+i);
		printf("%lld\n", getPermNum(P, N));
	}
}