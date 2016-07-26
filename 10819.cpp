#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
	int N, arr[8];
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", arr+i);
	sort(arr, arr+N);
	int result = 0;
	do{
		int sum = 0;
		for(int i=1; i<N; i++)
			sum += abs(arr[i]-arr[i-1]);
		result = max(result, sum);
	}while(next_permutation(arr, arr+N));
	printf("%d\n", result);
}