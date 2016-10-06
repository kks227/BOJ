#include <cstdio>
#include <algorithm>
using namespace std;
const int ST_MAX = 1<<18;

inline char StoC(int s){
	if(s == 0) return '0';
	return (s>0 ? '+' : '-');
}

inline int NtoS(int n){
	if(n == 0) return 0;
	return (n>0 ? 1 : -1);
}

struct SegTree{
	int arr[ST_MAX], start;
	SegTree(){
		fill(arr, arr+ST_MAX, 1);
		start = ST_MAX/2;
	}
	void construct(){
		for(int i=start-1; i>0; i--)
			arr[i] = arr[i*2]*arr[i*2+1];
	}
	void update(int n, int k){
		n += start;
		arr[n] = NtoS(k);
		while(n > 1){
			n /= 2;
			arr[n] = arr[n*2]*arr[n*2+1];
		}
	}
	int sign(int s, int e){ return sign(s, e, 1, 0, start); }
	int sign(int s, int e, int node, int ns, int ne){
		if(e <= ns || ne <= s) return 1;
		if(s <= ns && ne <= e) return arr[node];
		int mid = (ns+ne)/2;
		return sign(s, e, node*2, ns, mid) * sign(s, e, node*2+1, mid, ne);
	}
};

int main(){
	int N, K;
	while(scanf("%d %d", &N, &K) > 0){
		SegTree ST;
		for(int i=0; i<N; i++){
			int val;
			scanf("%d", &val);
			ST.arr[ST.start+i] = NtoS(val);
		}
		ST.construct();
		for(int i=0; i<K; i++){
			char c;
			int a, b;
			scanf(" %c %d %d", &c, &a, &b);
			if(c == 'C') ST.update(a-1, b);
			else putchar(StoC(ST.sign(a-1, b)));
		}
		puts("");
	}
}