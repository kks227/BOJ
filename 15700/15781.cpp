#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N[2], result[2] = {0,};
	scanf("%d %d", N, N+1);
	for(int i=0; i<2; i++){
		for(int j=0; j<N[i]; j++){
			int D;
			scanf("%d", &D);
			result[i] = max(D, result[i]);
		}
	}
	printf("%d\n", result[0]+result[1]);
}