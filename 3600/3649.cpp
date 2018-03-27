#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int X;
	while(scanf("%d", &X) > 0){
		int N, L[1000000];
		scanf("%d", &N);
		for(int i=0; i<N; i++)
			scanf("%d", L+i);
		sort(L, L+N);
		bool success = false;
		X *= 1e7;
		for(int i=0; i<N && L[i]<=X/2; i++){
			if(binary_search(L+i+1, L+N, X-L[i])){
				success = true;
				printf("yes %d %d\n", L[i], X-L[i]);
				break;
			}
		}
		if(!success) puts("danger");
	}
}