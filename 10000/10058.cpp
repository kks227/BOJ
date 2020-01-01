#include <cstdio>
#include <cassert>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 100;
const int INF = 1e9;

inline int d2(int x1, int y1, int x2 = 0, int y2 = 0){
	return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

inline int cross(int x1, int y1, int x2, int y2){
	return x1*y2 - x2*y1;
}

inline int ccw(int x1, int y1, int x2, int y2, int x3, int y3){
	return cross(x2-x1, y2-y1, x3-x1, y3-y1);
}

class HopcroftKarp{
public:
	int N, M;
	vector<int> adj[MAX];

	HopcroftKarp(vector<int> &L, vector<int> &R){
		N = L.size();
		M = R.size();
		for(int i = 0; i < L.size(); ++i)
			Anum[i] = L[i];
		for(int i = 0; i < R.size(); ++i)
			Bnum[i] = R[i];
	}

	void addEdge(int u, int v){ adj[u].push_back(v); }

	bool getResult(vector<int> &result){
		int match = 0;
		fill(A, A + N, -1);
		fill(B, B + M, -1);
		fill(used, used + N, false);
		while(1){
			bfs();
			int flow = 0;
			for(int i = 0; i < N; ++i)
				if(!used[i] && dfs(i)) ++flow;
			if(flow == 0) break;
			match += flow;
		}

		int K = N + M - match;
		if(result.size() >= K) return false;

		queue<int> Q;
		bool visitedA[MAX] = {false,}, visitedB[MAX] = {false,};
		for(int i = 0; i < N; ++i){
			if(A[i] == -1){
				Q.push(i);
				visitedA[i] = true;
			}
		}
		while(!Q.empty()){
			int a = Q.front(); Q.pop();
			for(int b: adj[a]){
				if(A[a] == b || visitedB[b]) continue;
				visitedB[b] = true;
				if(B[b] != -1 && !visitedA[B[b]]){
					visitedA[B[b]] = true;
					Q.push(B[b]);
				}
			}
		}

		result.clear();
		for(int i = 0; i < N; ++i)
			if(visitedA[i] || A[i] == -1) result.push_back(Anum[i]);
		for(int i = 0; i < M; ++i)
			if(!visitedB[i] || B[i] == -1) result.push_back(Bnum[i]);
		assert(K == result.size());
		return true;
	}

private:
	int A[MAX], B[MAX], Anum[MAX], Bnum[MAX], dist[MAX];
	bool used[MAX];

	void bfs(){
		queue<int> Q;
		for(int i = 0; i < N; ++i){
			if(!used[i]){
				dist[i] = 0;
				Q.push(i);
			}
			else dist[i] = INF;
		}

		while(!Q.empty()){
			int a = Q.front();
			Q.pop();
			for(int b: adj[a]){
				if(B[b] != -1 && dist[B[b]] == INF){
					dist[B[b]] = dist[a] + 1;
					Q.push(B[b]);
				}
			}
		}
	}

	bool dfs(int a){
		for(int b: adj[a]){
			if(B[b] == -1 || dist[B[b]] == dist[a]+1 && dfs(B[b])){
				used[a] = true;
				A[a] = b;
				B[b] = a;
				return true;
			}
		}
		return false;
	}
};



int main(){
	int N, D, x[MAX], y[MAX], r1 = -1, r2 = -1;
	scanf("%d %d", &N, &D);
	for(int i = 0; i < N; ++i)
		scanf("%d %d", x+i, y+i);

	vector<int> result;
	for(int i = 0; i < N; ++i){
		for(int j = i+1; j < N; ++j){
			int d = d2(x[i], y[i], x[j], y[j]);
			if(d > D*D) continue;
			if(r1 == -1){
				r1 = i;
				r2 = j;
			}

			vector<int> L, R;
			for(int k = 0; k < N; ++k){
				if(k == i || k == j) continue;
				if(d2(x[i], y[i], x[k], y[k]) > d || d2(x[j], y[j], x[k], y[k]) > d) continue;
				(ccw(x[i], y[i], x[j], y[j], x[k], y[k]) > 0 ? L : R).push_back(k);
			}
			HopcroftKarp G(L, R);
			for(int k = 0; k < L.size(); ++k)
				for(int l = 0; l < R.size(); ++l)
					if(d2(x[L[k]], y[L[k]], x[R[l]], y[R[l]]) > D*D) G.addEdge(k, l);
			if(G.getResult(result)){
				r1 = i;
				r2 = j;
			}
		}
	}
	if(r1 == -1){ printf("1\n1\n"); }
	else{
		result.push_back(r1);
		result.push_back(r2);
		printf("%d\n", result.size());
		for(int i: result)
			printf("%d ", i+1);
	}
}