#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++){
		int N;
		scanf("%d", &N);
		printf("Case %d: %d", t, N-1);
		for(int i=N; i>=0; i--){
			int c;
			scanf("%d", &c);
			if(i) printf(" %d", c*i);
		}
		puts("");
	}
}