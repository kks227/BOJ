#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, arr[1000000];
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", arr+i);
	sort(arr, arr+N);
	for(int i=N-1; i>=0; i--)
		printf("%d\n", arr[i]);
}