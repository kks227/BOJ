#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 1<<17;

char S[MAX];
int N, d, sa[MAX], pos[MAX], lcp[MAX];

bool cmp(int i, int j){
	if(pos[i] != pos[j]) return pos[i] < pos[j];
	i += d;
	j += d;
	return (i < N && j < N) ? (pos[i] < pos[j]) : (i > j);
}

void constructSA(){
	N = strlen(S);
	for(int i=0; i<N; i++){
		sa[i] = i;
		pos[i] = S[i];
	}
	for(d=1; ; d*=2){
		sort(sa, sa+N, cmp);
		int temp[MAX] = {0};
		for(int i=0; i<N-1; i++)
			temp[i+1] = temp[i] + cmp(sa[i], sa[i+1]);
		for(int i=0; i<N; i++)
			pos[sa[i]] = temp[i];

		if(temp[N-1] == N-1) break;
	}
}

void constructLCP(){
	for(int i=0, k=0; i<N; i++, k=max(k-1, 0)){
		if(pos[i] == N-1) continue;
		for(int j=sa[pos[i]+1]; S[i+k]==S[j+k]; k++);
		lcp[pos[i]] = k;
	}
}

int main(){
	scanf("%s", S);
	constructSA();
	constructLCP();
	int fail[MAX] = {0};
	for(int i=1, j=0; i<N; i++){
		while(j > 0 && S[i] != S[j]) j = fail[j-1];
		if(S[i] == S[j]) fail[i] = ++j;
	}

	int len[MAX], start[MAX], end[MAX], i, k = 0;
	for(int i=N-1; i>=0; i=fail[i]-1) len[k++] = i+1;
	int K = k;
	for(i=0; S[sa[i]] != S[0]; i++);
	for(; ; i++){
		if(k > 0 && lcp[i] == len[k-1]) start[--k] = i;
		while(k < K && lcp[i] < len[k]) end[k++] = i;
		if(lcp[i] == 0) break;
	}
	printf("%d\n", K);
	for(int i=K-1; i>=0; i--)
		printf("%d %d\n", len[i], end[i]-start[i]+1);
}