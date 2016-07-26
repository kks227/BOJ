#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, M, arr[100000];
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", arr+i);
	sort(arr, arr+N);
	scanf("%d", &M);
	for(int i=0; i<M; i++){
		int val;
		scanf("%d", &val);
		printf("%d\n", binary_search(arr, arr+N, val));
	}
}