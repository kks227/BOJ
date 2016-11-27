#include <cstdio>
#include <algorithm>
using namespace std;
const int ST_MAX = 1<<21;

struct SegTree{
	int arr[ST_MAX], start;
	SegTree(){
		fill(arr, arr+ST_MAX, 0);
		start = ST_MAX/2;
	}
	int get(int n){ return arr[start+n]; }
	void construct(){
		for(int i=start-1; i>0; i--)
			arr[i] = max(arr[i*2], arr[i*2+1]);
	}
	int getMax(int s, int e){ return getMax(s, e, 1, 0, start); }
	int getMax(int s, int e, int node, int ns, int ne){
		if(ne <= s || e <= ns) return 0;
		if(s <= ns && ne <= e) return arr[node];
		int mid = (ns+ne)/2;
		return max(getMax(s, e, node*2, ns, mid), getMax(s, e, node*2+1, mid, ne));
	}
};

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N;
		scanf("%d", &N);
		SegTree ST;
		for(int i=0; i<N; i++)
			scanf("%d", ST.arr+ST.start+i);
		ST.construct();

		long long result = 0;
		for(int i=0; i<N; i++)
			result += ST.getMax(i, N) - ST.get(i);
		printf("%lld\n", result);
	}
}