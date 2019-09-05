#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
const int MAX_N = 200000;
const int MAX = MAX_N * 4;
const int MAX_K = 1000001;

class Party{
public:
	void input(){
		scanf("%d", &N);
		fill(L, L+N*2, 0);
		for(int i = 0; i < N; ++i){
			for(int j = 0; j < 2; ++j){
				int k = i*2+j;
				scanf("%d %d", &A[k], &K[k]);
				--A[k];
				B[ A[k] ][ L[A[k]]++ ] = k;
			}
		}
	}

	int solve(){
		for(int i = 0; i < N; ++i){
			int a = i*4 + 1, b = i*4 + 3;
			adj[oppo(a)].push_back(b);
			adj[oppo(b)].push_back(a);
		}
		for(int i = 0; i < N*2; ++i){
			if(L[i] == 2){
				int a = B[i][0]*2, b = B[i][1]*2;
				adj[oppo(a)].push_back(b);
				adj[oppo(b)].push_back(a);
			}
		}

		int lo = -1, hi = MAX_K;
		while(lo+1 < hi){
			int mid = (lo+hi)/2;

			for(int i = 0; i < N*2; ++i){
				if(K[i] > mid){
					int a = i*2;
					adj[oppo(a)].push_back(a);
				}
			}

			cnt = scc = 0;
			fill(dfsn, dfsn + N*4, 0);
			fill(finished, finished + N*4, false);
			for(int i = 0; i < N*4; ++i)
				if(dfsn[i] == 0) dfs(i);
			bool flag = true;
			for(int i = 0; i < N*2; ++i){
				if(sccNum[i*2] == sccNum[i*2+1]){
					flag = false;
					break;
				}
			}

			for(int i = 0; i < N*2; ++i){
				if(K[i] > mid){
					int a = i*2;
					adj[oppo(a)].pop_back();
				}
			}

			(flag ? hi : lo) = mid;
		}
		return hi;
	}

private:
	int N, K[MAX_N*2], A[MAX_N*2], B[MAX_N*2][2], L[MAX_N*2];
	int cnt, scc, dfsn[MAX], sccNum[MAX];
	vector<int> adj[MAX];
	bool finished[MAX];
	stack<int> S;

	inline int oppo(int n){ return n%2 ? n-1 : n+1; }

	int dfs(int curr){
		dfsn[curr] = ++cnt;
		S.push(curr);
		int result = dfsn[curr];
		for(int next: adj[curr]){
			if(dfsn[next] == 0) result = min(result, dfs(next));
			else if(!finished[next]) result = min(result, dfsn[next]);
		}
		if(result >= dfsn[curr]){
			sccNum[curr] = scc++;
			while(1){
				int family = S.top();
				S.pop();
				finished[family] = true;
				if(family == curr) break;
				sccNum[family] = sccNum[curr];
			}
		}
		return result;
	}
};

int main(){
	Party solver;
	solver.input();
	int result = solver.solve();
	if(result == MAX_K) result = -1;
	printf("%d\n", result);
}