#include <cstdio>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
using namespace std;
const int MAX = 100000;
const int ST_MAX = 1<<18;
typedef tuple<int, int, int> QueryNode;

struct SegTree{
	long long arr[ST_MAX], lazy[ST_MAX];
	SegTree(){
		fill(arr, arr+ST_MAX, 0);
		fill(lazy, lazy+ST_MAX, 0);
	}
	void clear(){
		fill(arr, arr+ST_MAX, 0);
		fill(lazy, lazy+ST_MAX, 0);
	}
	void propagate(int node, int ns, int ne){
		if(lazy[node] != 0){
			if(node < ST_MAX/2){
				lazy[node*2] += lazy[node];
				lazy[node*2+1] += lazy[node];
			}
			arr[node] += lazy[node] * (ne-ns);
			lazy[node] = 0;
		}
	}
	void add(int s, int e, int k){ add(s, e, k, 1, 0, ST_MAX/2); }
	void add(int s, int e, int k, int node, int ns, int ne){
		propagate(node, ns, ne);
		if(e <= ns || ne <= s) return;
		if(s <= ns && ne <= e){
			lazy[node] += k;
			propagate(node, ns, ne);
			return;
		}
		int mid = (ns+ne)/2;
		add(s, e, k, node*2, ns, mid);
		add(s, e, k, node*2+1, mid, ne);
		arr[node] = arr[node*2] + arr[node*2+1];
	}
	long long sum(int s, int e){ return sum(s, e, 1, 0, ST_MAX/2); }
	long long sum(int s, int e, int node, int ns, int ne){
		propagate(node, ns, ne);
		if(e <= ns || ne <= s) return 0;
		if(s <= ns && ne <= e) return arr[node];
		int mid = (ns+ne)/2;
		return sum(s, e, node*2, ns, mid) + sum(s, e, node*2+1, mid, ne);
	}
};

int vcnt, vn[MAX], L[MAX], R[MAX], tSize[MAX];
vector<int> adj[MAX];

void dfs(int curr){
	vn[curr] = L[curr] = R[curr] = vcnt++;
	tSize[curr] = 1;
	for(int next: adj[curr]){
		dfs(next);
		R[curr] = R[next];
		tSize[curr] += tSize[next];
	}
}



int main(){
	int N, K, J;
	scanf("%d %d %d", &N, &K, &J);
	for(int i = 1; i < N; ++i){
		int p;
		scanf("%d", &p);
		adj[p-1].push_back(i);
	}
	dfs(0);

	int o[MAX], scnt[MAX] = {0};
	vector<int> pos[MAX];
	for(int i = 0; i < N; ++i){
		scanf("%d", o+i);
		pos[--o[i]].push_back(i);
		++scnt[o[i]];
	}

	QueryNode q[MAX];
	set<int> S;
	for(int i = 0; i < K; ++i){
		int t, p, s;
		scanf("%d %d %d", &t, &p, &s);
		S.insert(t);
		q[i] = QueryNode(t, p-1, s);
	}
	int M = 0, H2I[MAX];
	unordered_map<int, int> I2H;
	for(int i: S){
		H2I[M] = i;
		I2H[i] = M++;
	}
	for(int i = 0; i < K; ++i)
		get<0>(q[i]) = I2H[get<0>(q[i])];
	sort(q, q+K);

	int lo[MAX] = {0}, hi[MAX];
	fill(hi, hi+N, M+1);
	while(1){
		bool flag = false;
		vector<int> G[MAX+1];
		for(int i = 0; i < N; ++i){
			if(lo[i]+1 < hi[i]){
				flag = true;
				G[(lo[i]+hi[i])/2].push_back(i);
			}
		}
		if(!flag) break;

		SegTree ST;
		for(int i = 0, j = 0; i < M; ++i){
			do{
				int t, p, s;
				tie(t, p, s) = q[j];
				if(t > i) break;
				ST.add(L[p], R[p]+1, s/tSize[p]);
			}while(++j < K);

			for(int k: G[i+1]){
				long long temp = 0;
				for(int j: pos[k])
					temp += ST.sum(vn[j], vn[j]+1);
				(temp > 1LL*scnt[k]*J ? hi : lo)[k] = i+1;
			}
		}
	}

	for(int i = 0; i < N; ++i){
		if(lo[o[i]] == M) puts("-1");
		else printf("%d\n", H2I[ lo[o[i]] ]);
	}
}