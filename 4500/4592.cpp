#include <cstdio>
using namespace std;

int main(){
	while(1){
		int N;
		scanf("%d", &N);
		if(N == 0) break;

		int prev = -1;
		for(int i=0; i<N; i++){
			int val;
			scanf("%d", &val);
			if(prev != val) printf("%d ", val);
			prev = val;
		}
		puts("$");
	}
}