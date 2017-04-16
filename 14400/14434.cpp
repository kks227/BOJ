#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, M, K, Q, l[200000], cnt[200000] = {0}, sum = 0;
	vector<int> g[200000];
	scanf("%d %d %d %d", &N, &M, &K, &Q);
	for(int i=0; i<M; i++)
		scanf("%d", l+i);
	for(int i=0; i<K; i++){
		int child;
		scanf("%d", &child);
		g[child-1].push_back(i);
	}
	for(int i=0; i<Q; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		a--; b--; c--;
		if(l[c] == 1 && (!g[a].empty() && g[a][0] == 0 || !g[b].empty() && g[b][0] == 0)) cnt[0]++;
		else if((g[a].empty() ? 0 : g[a].back()) + (g[b].empty() ? 0 : g[b].back()) < l[c]) continue;
		else{
			int lo = 0, hi = K;
			while(lo+1 < hi){
				int mid = (lo+hi)/2;
				(upper_bound(g[a].begin(), g[a].end(), mid)-g[a].begin() + upper_bound(g[b].begin(), g[b].end(), mid)-g[b].begin() >= l[c] ? hi : lo) = mid;
			}
			cnt[hi]++;
		}
	}
	for(int i=0; i<K; i++){
		sum += cnt[i];
		printf("%d\n", sum);
	}
}