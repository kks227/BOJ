#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int V, cnt[1000] = {0}, result = 0, n = -1;
		scanf("%d", &V);
		for(int i=0; i<V; i++){
			int S;
			scanf("%d", &S);
			cnt[--S]++;
			if(cnt[S] > result || cnt[S] == result && n > S+1){
				result = cnt[S];
				n = S+1;
			}
		}
		printf("%d\n", n);
	}
}