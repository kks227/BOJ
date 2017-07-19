#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 1<<16;

char S[MAX];
int N, d, sa[MAX], pos[MAX], lcp[MAX];

bool cmp(int i, int j){
	if(pos[i] != pos[j]) return pos[i] < pos[j];
	i += d;
	j += d;
	return (i < N && j < N) ? (pos[i] < pos[j]) : (i > j);
}

void constructSA(){
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

void constructLCP(){
	for(int i=0, k=0; i<N; i++, k=max(k-1, 0)){
		if(pos[i] == N-1) continue;
		for(int j=sa[pos[i]+1]; S[i+k]==S[j+k]; k++);
		lcp[pos[i]] = k;
	}
}

int main(){
	while(1){
		int M;
		scanf("%d", &M);
		if(M == 0) break;

		scanf("%s", S);
		N = strlen(S);
		if(M == 1){
			printf("%d %d\n", N, 0);
			continue;
		}
		constructSA();
		constructLCP();
		int lo = 0, hi = N;
		while(lo+1 < hi){
			int mid = (lo+hi)/2;
			int temp = 0, cnt = 1;
			for(int i=0; i<N-1; i++){
				if(lcp[i] >= mid) temp = max(temp, ++cnt);
				else cnt = 1;
			}
			(temp >= M ? lo : hi) = mid;
		}
		if(lo == 0) puts("none");
		else{
			int result = -1, cnt = 1, temp = sa[N-1];
			for(int i=N-2; i>=0; i--){
				if(lcp[i] >= lo){
					temp = max(temp, sa[i]);
					if(++cnt >= M) result = max(result, temp);
				}
				else{
					cnt = 1;
					temp = sa[i];
				}
			}
			printf("%d %d\n", lo, result);
		}
	}
}