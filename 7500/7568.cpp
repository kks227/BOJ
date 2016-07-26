#include <cstdio>
using namespace std;

int main(){

	int N;
	int rank[50]={0}, weight[50], height[50];
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d %d", weight+i, height+i);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			if(weight[i]<weight[j] && height[i]<height[j]) rank[i]++;
	for(int i=0; i<N; i++)
		printf("%d ", rank[i]+1);

	return 0;
}