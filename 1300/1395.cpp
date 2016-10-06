#include <cstdio>
#include <algorithm>
using namespace std;
const int ST_MAX = 1<<18;

struct SegTree{
	int start, arr[ST_MAX];
	bool lazy[ST_MAX];
	SegTree(){
		start = ST_MAX/2;
		fill(arr, arr+ST_MAX, 0);
		fill(lazy, lazy+ST_MAX, false);
	}
	void propagate(int node, int ns, int ne){
		if(lazy[node]){
			if(node < start){
				lazy[node*2] ^= 1;
				lazy[node*2+1] ^= 1;

				int temp = 0;
				if(lazy[node*2]) temp += (ne-ns)/2 - arr[node*2];
				else temp += arr[node*2];
				if(lazy[node*2+1]) temp += (ne-ns)/2 - arr[node*2+1];
				else temp += arr[node*2+1];
				arr[node] = temp;
			}
			else arr[node] ^= 1;
			lazy[node] = false;
		}
	}
	void turn(int s, int e){ turn(s, e, 1, 0, start); }
	void turn(int s, int e, int node, int ns, int ne){
		propagate(node, ns, ne);
		if(e <= ns || ne <= s) return;
		if(s <= ns && ne <= e){
			lazy[node] ^= 1;
			propagate(node, ns, ne);
			return;
		}
		int mid = (ns+ne)/2;
		turn(s, e, node*2, ns, mid);
		turn(s, e, node*2+1, mid, ne);
		arr[node] = arr[node*2] + arr[node*2+1];
	}
	int cnt(int s, int e){ return cnt(s, e, 1, 0, start); }
	int cnt(int s, int e, int node, int ns, int ne){
		propagate(node, ns, ne);
		if(e <= ns || ne <= s) return 0;
		if(s <= ns && ne <= e) return arr[node];
		int mid = (ns+ne)/2;
		return cnt(s, e, node*2, ns, mid) + cnt(s, e, node*2+1, mid, ne);
	}
};

int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	SegTree ST;
	for(int i=0; i<M; i++){
		int O, S, T;
		scanf("%d %d %d", &O, &S, &T);
		if(O == 0) ST.turn(S-1, T);
		else printf("%d\n", ST.cnt(S-1, T));
	}
}