#include <cstdio>
#include <algorithm>
using namespace std;
 
int main(){

	int N;
	scanf("%d", &N);
	int arr[10000];
	for(int i=0; i<N; i++)
		scanf("%d", arr+i);
	sort(arr, arr+N);

	int result = 0, cons;
	for(int i=0; i<N; i++){
		cons = 1;
		for(int j=1; j<5 && i+j<N; j++)
			if(arr[i+j] < arr[i]+5) cons++;
		result = max(result, cons);
	}
	printf("%d\n", 5-result);

    return 0;
}