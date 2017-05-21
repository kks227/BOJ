#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
const int ST_MAX = 1<<18;
const int INF = 1e9 + 1;
typedef pair<int, int> P;

struct SegTree{
	int start;
	P arr[ST_MAX];
	SegTree(){
		start = ST_MAX/2;
		fill(arr, arr+ST_MAX, P(INF, -1));
	}
	void setLeaf(int n, int k){ arr[start+n] = P(k, n); }
	void construct(){
		for(int i=start-1; i>0; i--)
			arr[i] = min(arr[i*2], arr[i*2+1]);
	}
	void update(int n, int k){
		n += start;
		arr[n].first = k;
		while(n > 1){
			n /= 2;
			arr[n] = min(arr[n*2], arr[n*2+1]);
		}
	}
	P minIndex(int s, int e){ return minIndex(s, e, 1, 0, start); }
	P minIndex(int s, int e, int node, int ns, int ne){
		if(e <= ns || ne <= s) return P(INF, -1);
		if(s <= ns && ne <= e) return arr[node];
		int mid = (ns+ne)/2;
		return min(minIndex(s, e, node*2, ns, mid), minIndex(s, e, node*2+1, mid, ne));
	}
};

int main(){
	int N, M;
	SegTree ST;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int val;
		scanf("%d", &val);
		ST.setLeaf(i, val);
	}
	ST.construct();
	scanf("%d", &M);
	for(int i=0; i<M; i++){
		int op, a, b;
		scanf("%d %d %d", &op, &a, &b);
		if(op == 1) ST.update(a-1, b);
		else printf("%d\n", ST.minIndex(a-1, b).second + 1);
	}
}