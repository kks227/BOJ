#include <cstdio>
#include <vector>
#include <set>
#include <unordered_map>
#include <tuple>
#include <algorithm>
using namespace std;
const int MAX = 100000;
const int ST_MAX = 1<<20;
const int INF = 1e9;
typedef tuple<long long, int, int> QueryNode;

struct SegTree{
	long long arr[ST_MAX], lazy[ST_MAX], weight[ST_MAX];
	SegTree(){
		fill(arr, arr+ST_MAX, 0);
		fill(lazy, lazy+ST_MAX, 0);
		fill(weight, weight+ST_MAX, 0);
	}
	void clear(){
		fill(arr, arr+ST_MAX, 0);
		fill(lazy, lazy+ST_MAX, 0);
	}
	void construct(){
		for(int i = ST_MAX/2-1; i > 0; --i)
			weight[i] = weight[i*2] + weight[i*2+1];
	}
	void propagate(int node, int ns, int ne){
		if(lazy[node] != 0){
			if(node < ST_MAX/2){
				lazy[node*2] += lazy[node];
				lazy[node*2+1] += lazy[node];
			}
			arr[node] += lazy[node] * weight[node];
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



int main(){
	int N, Q[2];
	QueryNode q[2][MAX];
	set<int> valS, posS;
	scanf("%d %d %d", &N, Q, Q+1);
	for(int i = 0; i < 2; ++i){
		for(int j = 0; j < Q[i]; ++j){
			int a, b;
			long long c;
			scanf("%d %d %lld", &a, &b, &c);
			posS.insert(--a);
			posS.insert(b);
			if(i == 0) valS.insert(c);
			else --c;
			q[i][j] = QueryNode(c, a, b);
		}
	}

	SegTree ST;
	int M = 0, posPrev = 0, valH2I[MAX];
	unordered_map<int, int> posI2H, valI2H;
	posS.insert(0);
	posS.insert(INF);
	for(int i: posS){
		if(M > 0) ST.weight[ST_MAX/2 + M-1] = i - posPrev;
		posI2H[i] = M++;
		posPrev = i;
	}
	ST.construct();

	M = 0;
	for(int i: valS){
		valH2I[M] = i;
		valI2H[i] = M++;
	}
	sort(q[0], q[0] + Q[0]);
	for(int i = 0; i < 2; ++i){
		for(int j = 0; j < Q[i]; ++j){
			int a, b;
			long long c;
			tie(c, a, b) = q[i][j];
			q[i][j] = QueryNode(i > 0 ? c : valI2H[c], posI2H[a], posI2H[b]);
		}
	}

	int lo[MAX] = {0}, hi[MAX];
	fill(hi, hi+Q[1], M+1);
	while(1){
		bool flag = false;
		vector<int> G[MAX+1];
		for(int i = 0; i < Q[1]; ++i){
			if(lo[i]+1 < hi[i]){
				flag = true;
				G[(lo[i]+hi[i])/2].push_back(i);
			}
		}
		if(!flag) break;

		for(int i = 0, j1 = 0; i < M; ++i){
			// q[0]: update
			while(j1 < Q[0]){
				int s, e;
				long long k;
				tie(k, s, e) = q[0][j1];
				if(k > i) break;
				ST.add(s, e, 1);
				++j1;
			}

			// q[1]: find k-th
			for(int j2: G[i+1]){
				int s, e;
				long long k;
				tie(k, s, e) = q[1][j2];
				(ST.sum(s, e) > k ? hi : lo)[j2] = i+1;
			}
		}

		ST.clear();
	}

	for(int i = 0; i < Q[1]; ++i)
		printf("%d\n", valH2I[lo[i]]);
}