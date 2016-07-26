#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int K;
	scanf("%d", &K);
	for(int k=1; k<=K; k++){
		int N, S[50], gap = 0;
		scanf("%d", &N);
		for(int i=0; i<N; i++)
			scanf("%d", S+i);
		sort(S, S+N);
		for(int i=0; i<N-1; i++)
			gap = max(gap, S[i+1]-S[i]);
		printf("Class %d\n", k);
		printf("Max %d, Min %d, Largest gap %d\n", S[N-1], S[0], gap);
	}
}