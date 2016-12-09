#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N, X[1000], result = 0;
		scanf("%d", &N);
		for(int i=0; i<N; i++)
			scanf("%d", X+i);
		sort(X, X+N);
		for(int i=0; i<N-2; i++)
			for(int j=i+1; j<N-1; j++)
				if(binary_search(X+j+1, X+N, 2*X[j]-X[i])) result++;
		printf("%d\n", result);
	}
}