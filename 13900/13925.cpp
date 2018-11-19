#include <cstdio>
#include <algorithm>
using namespace std;
const int ST_MAX = 1<<18;
const int MOD = 1000000007;

struct SegTree{
	int arr[ST_MAX], lazy[2][ST_MAX]; // ax + b
	SegTree(){
		fill(arr, arr+ST_MAX, 0);
		fill(lazy[0], lazy[0]+ST_MAX, 1);
		fill(lazy[1], lazy[1]+ST_MAX, 0);
	}
	void construct(){
		for(int i = ST_MAX/2-1; i > 0; --i)
			arr[i] = (arr[i*2] + arr[i*2+1]) % MOD;
	}
	void propagate(int node, int ns, int ne){
		int &a1 = lazy[0][node], &b1 = lazy[1][node];
		if(a1 != 1 || b1 != 0){
			if(node < ST_MAX/2){
				for(int nnode = node*2; nnode <= node*2+1; ++nnode){
					int a2 = lazy[0][nnode], b2 = lazy[1][nnode];
					lazy[0][nnode] = (1LL*a1*a2) % MOD;
					lazy[1][nnode] = (b1 + 1LL*a1*b2) % MOD;
				}
			}
			arr[node] = (1LL*a1*arr[node] + 1LL*b1*(ne-ns)) % MOD;
			a1 = 1;
			b1 = 0;
		}
	}
	void operate(int s, int e, char op, int k){ operate(s, e, op, k, 1, 0, ST_MAX/2); }
	void operate(int s, int e, char op, int k, int node, int ns, int ne){
		propagate(node, ns, ne);
		if(e <= ns || ne <= s) return;
		if(s <= ns && ne <= e){
			if(op == '+') lazy[1][node] = (lazy[1][node] + k) % MOD;
			else if(op == '*'){
				lazy[0][node] = (1LL*lazy[0][node]*k) % MOD;
				lazy[1][node] = (1LL*lazy[1][node]*k) % MOD;
			}
			else{
				lazy[0][node] = 0;
				lazy[1][node] = k % MOD;
			}
			propagate(node, ns, ne);
			return;
		}
		int mid = (ns+ne)/2;
		operate(s, e, op, k, node*2, ns, mid);
		operate(s, e, op, k, node*2+1, mid, ne);
		arr[node] = (arr[node*2] + arr[node*2+1]) % MOD;
	}
	int sum(int s, int e){ return sum(s, e, 1, 0, ST_MAX/2); }
	int sum(int s, int e, int node, int ns, int ne){
		propagate(node, ns, ne);
		if(e <= ns || ne <= s) return 0;
		if(s <= ns && ne <= e) return arr[node] % MOD;
		int mid = (ns+ne)/2;
		return (sum(s, e, node*2, ns, mid) + sum(s, e, node*2+1, mid, ne)) % MOD;
	}
};

int main(){
	int N, M;
	scanf("%d", &N);
	SegTree ST;
	for(int i = 0; i < N; ++i)
		scanf("%d", ST.arr+ST_MAX/2+i);
	ST.construct();

	scanf("%d", &M);
	for(int i = 0; i < M; ++i){
		int o, x, y, v;
		scanf("%d %d %d", &o, &x, &y);
		if(o == 4){
			printf("%d\n", ST.sum(x-1, y));
		}
		else{
			scanf("%d", &v);
			ST.operate(x-1, y, (o==1 ? '+' : (o==2 ? '*' : '=')), v);
		}
	}
}