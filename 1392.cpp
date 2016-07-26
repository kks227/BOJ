#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, Q, T[100];
	scanf("%d %d %d", &N, &Q, T);
	for(int i=1; i<N; i++){
		scanf("%d", T+i);
		T[i] += T[i-1];
	}
	for(int i=0; i<Q; i++){
		int t;
		scanf("%d", &t);
		printf("%d\n", lower_bound(T, T+N, t+1)-T+1);
	}
}