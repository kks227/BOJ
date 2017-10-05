#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 1<<18;

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
	int A = strlen(S);
	S[A++] = '$';
	scanf("%s", S+A);
	constructSA();
	constructLCP();

	int result = 0, pos = 0, B = N - A;
	for(int i=0; i<N-1; i++){
		if((sa[i] >= A) != (sa[i+1] >= A)){
			int temp = min(lcp[i], A-1 - min(sa[i], sa[i+1]));
			if(temp > result){
				result = temp;
				pos = sa[i];
			}
		}
	}
	printf("%d\n", result);
	for(int i=0; i<result; i++)
		putchar(S[pos+i]);
}