#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int M, rSum[10000];
		scanf("%d %d", &M, rSum);
		for(int i=1; i<M; i++){
			scanf("%d", rSum+i);
			rSum[i] += rSum[i-1];
		}

		int result = rSum[M-1];
		for(int i=0; i<M-1; i++){
			if(rSum[M-1]%rSum[i]) continue;
			int current = rSum[i], j;
			for(j=i+1; j<M; j++){
				if(rSum[j]-current > rSum[i]) break;
				if(rSum[j]-current == rSum[i]) current += rSum[i];
			}
			if(j==M && current==rSum[M-1]){
				result = rSum[i];
				break;
			}
		}
		printf("%d\n", result);
	}
}