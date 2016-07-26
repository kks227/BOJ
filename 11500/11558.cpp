#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N, next[10000];
		scanf("%d", &N);
		for(int i=0; i<N; i++){
			scanf("%d", next+i);
			next[i]--;
		}
		int cur = 0, cnt;
		for(cnt=0; cnt<N; cnt++){
			if(cur == N-1){
				printf("%d\n", cnt);
				break;
			}
			cur = next[cur];
		}
		if(cnt == N) puts("0");
	}
}