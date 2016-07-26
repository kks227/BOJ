#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, M, val[100], result = 0;
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++)
		scanf("%d", val+i);
	for(int i=0; i<N-2; i++)
		for(int j=i+1; j<N-1; j++)
			for(int k=j+1; k<N; k++){
				int cost = val[i]+val[j]+val[k];
				if(cost <= M) result = max(cost, result);
			}
	printf("%d\n", result);
}