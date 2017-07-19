#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 1<<17;

char S[MAX];
int N, d, sa[MAX], pos[MAX];


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
		int temp[MAX];
		for(int i=0; i<N-1; i++)
			temp[i+1] = temp[i] + cmp(sa[i], sa[i+1]);
		for(int i=0; i<N; i++)
			pos[sa[i]] = temp[i];

		if(temp[N-1] == N-1) break;
	}
}

int main(){
	scanf("%s", S);
	constructSA();
	for(int i=0; i<N; i++)
		printf("%d\n", sa[i]);
}