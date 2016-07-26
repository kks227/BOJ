#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
	scanf("%d", &N);
	do{
		for(int i=0; i<N; i++)
			printf("%d ", arr[i]);
		puts("");
	}while(next_permutation(arr, arr+N));
}