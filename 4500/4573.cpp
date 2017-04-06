#include <cstdio>
using namespace std;

int main(){
	for(int t=1; ; t++){
		int N;
		scanf("%d", &N);
		if(N == 0) break;

		int D[10], P[10];
		for(int i=0; i<N; i++)
			scanf("%d %d", D+i, P+i);
		for(int i=0; i<N; i++){
			bool best = true;
			for(int j=0; j<N; j++){
				if(i == j) continue;
				if(D[i]*D[i]*P[j] < D[j]*D[j]*P[i]){
					best = false;
					break;
				}
			}
			if(best){
				printf("Menu %d: %d\n", t, D[i]);
				break;
			}
		}
	}
}