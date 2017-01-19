#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1<<19;

struct SegTree{
	vector<int> arr[MAX];
	void construct(){
		for(int i=MAX/2-1; i>0; i--){
			vector<int> &c = arr[i], &l = arr[i*2], &r = arr[i*2+1];
			arr[i].resize(l.size()+r.size());
			for(int j=0, p=0, q=0; j<c.size(); j++){
				if(q == r.size() || (p < l.size() && l[p] < r[q])) c[j] = l[p++];
				else c[j] = r[q++];
			}
		}
	}
	int less(int s, int e, int k){ return less(s, e, k, 1, 0, MAX/2); }
	int less(int s, int e, int k, int node, int ns, int ne){
		if(ne <= s || e <= ns) return 0;
		if(s <= ns && ne <= e) return lower_bound(arr[node].begin(), arr[node].end(), k) - arr[node].begin();
		int mid = (ns+ne)/2;
		return less(s, e, k, node*2, ns, mid) + less(s, e, k, node*2+1, mid, ne);
	}
};

int main(){
	int N, K, M = -1;
	SegTree ST;
	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++){
		int val;
		scanf("%d", &val);
		ST.arr[MAX/2+i].push_back(val);
		M = max(M, val);
	}
	ST.construct();
	
	long long result = 0;
	for(int i=0; i<N-K+1; i++){
		int lo = -1, hi = M+1;
		while(lo+1 < hi){
			int mid = (lo+hi)/2;
			(ST.less(i, i+K, mid) < (K+1)/2 ? lo : hi) = mid;
		}
		result += lo;
	}
	printf("%lld\n", result);
}