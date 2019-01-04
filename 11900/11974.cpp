#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, pMin[7] = {0,}, pMax[7] = {0,};
	scanf("%d", &N);
	for(int i = 0, pSum = 0; i < N; ++i){
		int A;
		scanf("%d", &A);
		pSum = (pSum + A) % 7;
		if(pSum > 0 && pMin[pSum] == 0) pMin[pSum] = i+1;
		pMax[pSum] = i+1;
	}
	int result = 0;
	for(int i = 0; i < 7; ++i)
		result = max(pMax[i]-pMin[i], result);
	printf("%d\n", result);
}