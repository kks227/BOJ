#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++){
		int N;
		scanf("%d", &N);
		printf("Case %d:\n", t);
		for(int i=0; i<N; i++){
			int g;
			scanf("%d", &g);
			if(g < 6) printf("%d\n", g+1);
		}
	}
}