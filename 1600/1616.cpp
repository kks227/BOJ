#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 10000000;
const int MAX_N = MAX/2;

class Graph{
public:
	bool input(){
		scanf("%d %d", &B, &L);
		M = pow(B, L);
		N = M / B;
		if(L == 1){
			for(int i = 0; i < B; ++i)
				printf("%d ", i);
			puts("");
			return false;
		}

		int degree[MAX_N] = {0,};
		for(int i = 0; i < N; ++i)
			adjS[i] = adjE[i] = i*B;
		for(int i = 0; i < N; ++i){
			for(int k = 0; k < B; ++k){
				int j = (1LL*i*B + k) % N;
				adj[ adjE[i]++ ] = j;
				++degree[j];
				--degree[i];
			}
		}
		for(int i = 0; i < N; ++i){
			if(degree[i] != 0){
				puts("-1");
				return false;
			}
		}
		return true;
	}

	bool isConnected(){
		bool visited[MAX_N] = {true,};
		queue<int> Q;
		int vcnt = 1;
		Q.push(0);
		while(!Q.empty()){
			int curr = Q.front(); Q.pop();
			for(int i = adjS[curr]; i < adjE[curr]; ++i){
				int next = adj[i];
				if(!visited[next]){
					visited[next] = true;
					++vcnt;
					Q.push(next);
				}
			}
		}

		if(vcnt < N){
			puts("-1");
			return false;
		}
		return true;
	}

	void solve(){
		int fcnt = 0, p = 0, prev = -1, S[MAX+1] = {0,};
		while(p >= 0){
			int curr = S[p];
			if(adjS[curr] == adjE[curr]){
				--p;
				if(prev >= 0) printf("%d ", curr%B);
				prev = curr;
			}
			else{
				int next = adj[ adjS[curr]++ ];
				S[++p] = next;
			}
		}
		puts("");
	}

private:
	int N, M, B, L, adj[MAX], adjS[MAX_N], adjE[MAX_N];
};



int main(){
	Graph G;
	if(G.input() && G.isConnected()) G.solve();
}