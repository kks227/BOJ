#include <cstdio>
#include <algorithm>
using namespace std;

char S[531442];
int L[13] = {1};

void dfs(int k, int s, int e){
	if(k == 0) return;
	int a = s + L[k-1], b = a + L[k-1];
	for(int i=a; i<b; i++) S[i] = ' ';
	dfs(k-1, s, a);
	dfs(k-1, b, e);
}

int main(){
	for(int i=1; i<13; i++) L[i] = L[i-1] * 3;
	fill(S, S+531441, '-');
	dfs(12, 0, 531441);
	int N;
	while(scanf("%d", &N) > 0){
		for(int i=0; i<L[N]; i++) putchar(S[i]);
		puts("");
	}
}