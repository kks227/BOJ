#include <cstdio>
using namespace std;
const int MAX = 3000000;

int main(){
	int N, tSize[MAX] = {0,}, sCnt[MAX+1] = {0,}, p[MAX] = {-1,};
	scanf("%d", &N);
	for(int i = 1; i < N; ++i){
		scanf("%d", p+i);
		--p[i];
	}
	for(int i = N-1; i >= 0; --i){
		++sCnt[++tSize[i]];
		if(i > 0) tSize[p[i]] += tSize[i];
	}
	for(int i = 1; i <= N; ++i){
		if(N%i != 0) continue;
		int cnt = 0, k = N/i;
		for(int j = k; j <= N; j += k)
			cnt += sCnt[j];
		if(cnt >= i) printf("%d ", i);
	}
}