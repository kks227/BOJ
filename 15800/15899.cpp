#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 200000;
const int MAX_ST = 1<<19;
const int MOD = 1000000007;

struct MergesortTree{
	vector<int> arr[MAX_ST];

	void construct(){
		for(int i = MAX_ST/2-1; i > 0; --i){
			vector<int> &c = arr[i], &l = arr[i*2], &r = arr[i*2+1];
			arr[i].resize(l.size()+r.size());
			for(int j = 0, p = 0, q = 0; j < c.size(); ++j){
				if(q == r.size() || (p < l.size() && l[p] < r[q])) c[j] = l[p++];
				else c[j] = r[q++];
			}
		}
	}
	int leq(int s, int e, int k, int node = 1, int ns = 0, int ne = MAX_ST/2){
		if(ne <= s || e <= ns) return 0;
		if(s <= ns && ne <= e)
			return upper_bound(arr[node].begin(), arr[node].end(), k) - arr[node].begin();
		int mid = (ns+ne)/2;
		return leq(s, e, k, node*2, ns, mid) + leq(s, e, k, node*2+1, mid, ne);
	}
};

class TreeColor{
public:
	void solve(){
		int Q, C, col[MAX];
		scanf("%d %d %d", &N, &Q, &C);
		for(int i = 0; i < N; ++i)
			scanf("%d", col+i);
		for(int i = 0; i < N-1; ++i){
			int u, v;
			scanf("%d %d", &u, &v);
			--u; --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		dcnt = 0;
		dfs(0, -1);
		for(int i = 0; i < N; ++i)
			ST.arr[MAX_ST/2 + L[i]].push_back(col[i]);
		ST.construct();

		int result = 0;
		for(int i = 0; i < Q; ++i){
			int v, c;
			scanf("%d %d", &v, &c);
			--v;
			result = (ST.leq(L[v], R[v]+1, c) + result) % MOD;
		}
		printf("%d\n", result);
	}

private:
	int N, dcnt, L[MAX], R[MAX];
	vector<int> adj[MAX];
	MergesortTree ST;

	void dfs(int curr, int prev){
		L[curr] = R[curr] = dcnt++;
		for(int next: adj[curr]){
			if(next != prev){
				dfs(next, curr);
				L[curr] = min(L[next], L[curr]);
				R[curr] = max(R[next], R[curr]);
			}
		}
	}
};



int main(){
	TreeColor solver;
	solver.solve();
}