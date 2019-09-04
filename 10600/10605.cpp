#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 300;
const int MAX_VAL = 100001;
typedef pair<int, int> P;

int main(){
	while(1){
		int N, M, K;
		scanf("%d %d %d", &N, &M, &K);
		if(N == 0) break;

		vector<P> dragon[MAX];
		vector<int> adj[MAX];
		for(int i = 0; i < M; ++i){
			int u, v;
			scanf("%d %d", &u, &v);
			--u; --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for(int i = 0; i < K; ++i){
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			dragon[a-1].push_back(P(b, c));
		}

		int result = 0;
		bool visited[MAX] = {false,};
		for(int i = 0; i < N; ++i){
			if(visited[i]) continue;

			queue<int> Q;
			vector<int> pos;
			visited[i] = true;
			Q.push(i);
			int dcnt = 0;
			while(!Q.empty()){
				int curr = Q.front(); Q.pop();
				pos.push_back(curr);
				dcnt += dragon[curr].size();
				for(int next: adj[curr]){
					if(!visited[next]){
						visited[next] = true;
						Q.push(next);
					}
				}
			}
			if(dcnt == 0) continue;

			int lo = 0, hi = MAX_VAL;
			while(lo+1 < hi){
				int mid = (lo+hi)/2, temp = 0;
				for(int j: pos)
					for(auto &p: dragon[j])
						if(p.second >= mid) temp += p.first;
				(temp <= mid ? hi : lo) = mid;
			}
			result += hi;
		}
		printf("%d\n", result);
	}
}