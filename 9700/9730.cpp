#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++){
		int N, prev, curr, result = 0;
		scanf("%d", &N);
		for(int i=0; i<N; i++){
			scanf("%d", &curr);
			if(i > 0) result += max(prev, curr);
			prev = curr;
		}
		printf("Case #%d: %d\n", t, result);
	}
}