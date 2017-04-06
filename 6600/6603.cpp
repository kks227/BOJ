#include <cstdio>
using namespace std;

int K, S[13], L[6];

void dfs(int pos, int cnt){
	if(pos == K){
		for(int i=0; i<6; i++)
			printf("%d ", L[i]);
		puts("");
		return;
	}

	if(cnt < 6){
		L[cnt] = S[pos];
		dfs(pos+1, cnt+1);
	}
	if(K-pos > 6-cnt) dfs(pos+1, cnt);
}

int main(){
	while(1){
		scanf("%d", &K);
		if(K == 0) break;
		for(int i=0; i<K; i++)
			scanf("%d", S+i);
		dfs(0, 0);
		puts("");
	}
}