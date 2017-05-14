#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

int main(){
	int N, K, D, d[100000];
	bool know[100000][30] = {0};
	P p[100000];
	scanf("%d %d %d", &N, &K, &D);
	for(int i=0; i<N; i++){
		int M;
		scanf("%d %d", &M, d+i);
		for(int j=0; j<M; j++){
			int k;
			scanf("%d", &k);
			know[i][k-1] = true;
		}
		p[i] = P(d[i], i);
	}
	sort(p, p+N);

	int lo = 0, hi = 0, result = 0, cnt[30] = {0};
	while(lo < N){
		int s = p[lo].second;
		if(hi < N && p[hi].first-p[lo].first <= D){
			int e = p[hi].second, cnt1 = 0, cnt2 = 0;
			for(int i=0; i<K; i++){
				if(know[e][i]) cnt[i]++;
				if(cnt[i] > 0) cnt1++;
				if(cnt[i] == hi-lo+1) cnt2++;
			}
			result = max(result, (hi-lo+1)*(cnt1-cnt2));
			hi++;
		}
		else{
			for(int i=0; i<K; i++)
				if(know[s][i]) cnt[i]--;
			lo++;
		}
	}
	printf("%d\n", result);
}