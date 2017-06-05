#include <cstdio>
using namespace std;

int main(){
	while(1){
		int K, M;
		scanf("%d", &K);
		if(K == 0) break;

		scanf("%d", &M);
 		bool used[10000] = {0}, result = true;
		for(int i=0; i<K; i++){
			int n;
			scanf("%d", &n);
			used[n] = true;
		}
		for(int i=0; i<M; i++){
			int C, R, cnt = 0;
			scanf("%d %d", &C, &R);
			for(int j=0; j<C; j++){
				int n;
				scanf("%d", &n);
				if(used[n]) cnt++;
			}
			if(cnt < R) result = false;
		}
		puts(result ? "yes" : "no");
	}
}