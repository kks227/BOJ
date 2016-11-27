#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N, L[10000];
		scanf("%d", &N);
		for(int i=0; i<N; i++)
			scanf("%d", L+i);
		sort(L, L+N);
		
		int result = 0, left = L[0], right = L[0];
		for(int i=1; i<N-1; i++){
			if(left < right){
				result = max(result, L[i]-left);
				left = L[i];
			}
			else{
				result = max(result, L[i]-right);
				right = L[i];
			}
		}
		result = max(result, max(L[N-1]-left, L[N-1]-right));
		printf("%d\n", result);
	}
}