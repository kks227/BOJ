#include <cstdio>
using namespace std;

int main(){
	int N, arr[100], result = 0;
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", arr+i);
	for(int i=N-2; i>=0; i--){
		if(arr[i] >= arr[i+1]){
			result += arr[i]-arr[i+1]+1;
			arr[i] = arr[i+1]-1;
		}
	}
	printf("%d\n", result);
}