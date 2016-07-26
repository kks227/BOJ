#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int K, V, E, pre[1000]={0}, S[1000]={0}, cnt[1000]={0};
		vector<int> suc[1000];
		scanf("%d %d %d", &K, &V, &E);
		for(int i=0; i<E; i++){
			int A, B;
			scanf("%d %d", &A, &B);
			A--; B--;
			suc[A].push_back(B);
			pre[B]++;
		}
		queue<int> Q;
		for(int i=0; i<V; i++)
			if(pre[i] == 0) Q.push(i);
		int result = 0;
		for(int i=0; i<V; i++){
			int u = Q.front();
			Q.pop();
			if(S[u] == 0) S[u] = 1;
			else if(cnt[u] > 1) S[u]++;
			if(S[u] > result) result = S[u];
			for(int v: suc[u]){
				if(S[v] == S[u]) cnt[v]++;
				else if(S[v] < S[u]){
					S[v] = S[u];
					cnt[v] = 1;
				}
				if(--pre[v] == 0) Q.push(v);
			}
		}
		printf("%d %d\n", K, result);
	}
}