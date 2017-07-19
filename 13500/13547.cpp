#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int ST_MAX = 1<<18;
const int INF = 1e9;

struct SegTree{
	int start;
	vector<int> arr[ST_MAX];
	SegTree(): start(ST_MAX/2){}
	void set(int n, int k){ arr[n+start].push_back(k); }
	void construct(){
		for(int i=start-1; i>0; i--){
			int L = arr[i*2].size(), R = arr[i*2+1].size();
			for(int l=0, r=0; l<L || r<R;){
				if(l == L || r < R && arr[i*2][l] > arr[i*2+1][r]) arr[i].push_back(arr[i*2+1][r++]);
				else arr[i].push_back(arr[i*2][l++]);
			}
		}
	}
	// count the number of values s.t. >= k in [s, e)
	int cnt(int s, int e, int k){ return cnt(s, e, k, 1, 0, start); }
	int cnt(int s, int e, int k, int node, int ns, int ne){
		if(e <= ns || ne <= s) return 0;
		if(s <= ns && ne <= e)
			return arr[node].end() - lower_bound(arr[node].begin(), arr[node].end(), k);
		int mid = (ns+ne)/2;
		return cnt(s, e, k, node*2, ns, mid) + cnt(s, e, k, node*2+1, mid, ne);
	}
};

int main(){
	int N, M, A[1000000], last[1000001];
	SegTree ST;
	fill(last, last+1000001, INF);
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", A+i);
	for(int i=N-1; i>=0; i--){
		ST.set(i, last[A[i]]);
		last[A[i]] = i;
	}
	ST.construct();
	scanf("%d", &M);
	for(int i=0; i<M; i++){
		int s, e;
		scanf("%d %d", &s, &e);
		printf("%d\n", ST.cnt(s-1, e, e));
	}
}