#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N, val[100000];
		scanf("%d", &N);
		for(int i=0; i<N; i++){
			int a, b;
			scanf("%d %d", &a, &b);
			val[a-1] = b-1;
		}
		int result = 0, k = N;
		for(int i=0; i<N; i++)
			if(val[i] < k){
				result++;
				k = val[i];
			}
		printf("%d\n", result);
	}
}