#include <cstdio>
#include <algorithm>
using namespace std;

int N, M, A[8], val[8], cnt[8];

void dfs(int k){
	if(k == M){
		for(int i=0; i<M; i++)
			printf("%d ", val[A[i]]);
		puts("");
		return;
	}
	for(int i=0; i<N; i++){
		if(cnt[i] > 0){
			A[k] = i;
			cnt[i]--;
			dfs(k+1);
			cnt[i]++;
		}
	}
}

int main(){
	int temp[8], j = 0;
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++)
		scanf("%d", temp+i);
	sort(temp, temp+N);
	val[0] = temp[0];
	cnt[0]++;
	for(int i=1; i<N; i++){
		if(temp[i] != temp[i-1]) val[++j] = temp[i];
		cnt[j]++;
	}
	N = j+1;
	dfs(0);
}