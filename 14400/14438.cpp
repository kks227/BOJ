#include <cstdio>
#include <algorithm>
using namespace std;
const int ST_MAX = 1<<18;
const int INF = 1e9 + 1;

struct SegTree{
	int start, arr[ST_MAX];
	SegTree(){
		start = ST_MAX/2;
		fill(arr, arr+ST_MAX, INF);
	}
	void setLeaf(int n, int k){ arr[start+n] = k; }
	void construct(){
		for(int i=start-1; i>0; i--)
			arr[i] = min(arr[i*2], arr[i*2+1]);
	}
	void update(int n, int k){
		n += start;
		arr[n] = k;
		while(n > 1){
			n /= 2;
			arr[n] = min(arr[n*2], arr[n*2+1]);
		}
	}
	int getMin(int s, int e){ return getMin(s, e, 1, 0, start); }
	int getMin(int s, int e, int node, int ns, int ne){
		if(e <= ns || ne <= s) return INF;
		if(s <= ns && ne <= e) return arr[node];
		int mid = (ns+ne)/2;
		return min(getMin(s, e, node*2, ns, mid), getMin(s, e, node*2+1, mid, ne));
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
		else printf("%d\n", ST.getMin(a-1, b));
	}
}