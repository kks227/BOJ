#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 100000;
const int ST_MAX = 262144;

struct SegTree{
	int size, start;
	long long arr[ST_MAX];
	SegTree(int n){
		size = n;
		start = 1;
		while(start < size) start *= 2;
		memset(arr, 0, sizeof(arr));
	}
	void change(int i, long long val){
		i += start;
		arr[i] = val;
		while(i > 1){
			i /= 2;
			arr[i] = arr[i*2] + arr[i*2+1];
		}
	}
	long long sum(int s, int e){ return sum(s, e, 1, 0, start); }
	long long sum(int s, int e, int node, int ns, int ne){
		if(e <= ns || ne <= s) return 0;
		if(s <= ns && ne <= e) return arr[node];
		int mid = (ns+ne)/2;
		return sum(s, e, node*2, ns, mid) + sum(s, e, node*2+1, mid, ne);
	}
};

int main(){
	int N, Q;
	scanf("%d %d", &N, &Q);
	SegTree ST(N);
	for(int i=0; i<N; i++){
		int val;
		scanf("%d", &val);
		ST.change(i, val);
	}
	for(int i=0; i<Q; i++){
		int x, y, a, b;
		scanf("%d %d %d %d", &x, &y, &a, &b);
		if(x > y) swap(x, y);
		printf("%lld\n", ST.sum(x-1, y));
		ST.change(a-1, b);
	}
}