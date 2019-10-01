#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 200000;

int N, val[MAX], mcnt, lChild[MAX], rChild[MAX];
char op[MAX];

void dfs(int root, bool plus = true){
	if(root < N){
		if(!plus) ++mcnt;
		return;
	}
	dfs(lChild[root], plus);
	dfs(rChild[root], (op[root] == '-' ? !plus : plus));
}

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		scanf("%d", val+i);
	for(int i = 0; i < N-1; ++i){
		scanf(" %c %d %d", op+N+i, lChild+N+i, rChild+N+i);
		--lChild[N+i]; --rChild[N+i];
	}
	dfs(N*2-2);
	sort(val, val+N);
	int result = 0;
	for(int i = 0; i < N; ++i)
		result += (i < mcnt ? -1 : 1) * val[i];
	printf("%d\n", result);
}