#include <cstdio>
using namespace std;

int main(){
	for(int t=1; ; t++){
		int N, H[50], sum = 0;
		scanf("%d", &N);
		if(N == 0) break;

		for(int i=0; i<N; i++){
			scanf("%d", H+i);
			sum += H[i];
		}
		int M = sum / N, result = 0;
		for(int i=0; i<N; i++)
			if(H[i] > M) result += H[i] - M;
		printf("Set #%d\nThe minimum number of moves is %d.\n\n", t, result);
	}
}