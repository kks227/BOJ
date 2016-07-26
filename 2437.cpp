#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, weight[1000];
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", weight+i);
	sort(weight, weight+N);

	int result = 0;
	for(int i=0; i<N; i++){
		if(weight[i] > result+1) break;
		result += weight[i];
	}
	printf("%d\n", result+1);
}