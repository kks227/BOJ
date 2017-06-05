#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N[2], H[2][1000];
		for(int i=0; i<2; i++){
			scanf("%d", N+i);
			for(int j=0; j<N[i]; j++)
				scanf("%d", &H[i][j]);
		}
		int result = 1e9;
		for(int i=0; i<N[0]; i++)
			for(int j=0; j<N[1]; j++)
				result = min(result, abs(H[0][i]-H[1][j]));
		printf("%d\n", result);
	}
}