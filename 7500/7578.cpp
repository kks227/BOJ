#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int MAX = 500000;
const int ST_MAX = 1048576;

struct SegTree{
	int size, start;
	int arr[ST_MAX];
	SegTree(int n){
		size = n;
		start = 1;
		while(start < size) start *= 2;
		memset(arr, 0, sizeof(arr));
	}
	void inc(int i){
		i += start;
		while(i > 0){
			arr[i]++;
			i /= 2;
		}
	}
	int sum(int s, int e){ return sum(s, e, 1, 0, start); }
	int sum(int s, int e, int node, int ns, int ne){
		if(e <= ns || ne <= s) return 0;
		if(s <= ns && ne <= e) return arr[node];
		int mid = (ns+ne)/2;
		return sum(s, e, node*2, ns, mid) + sum(s, e, node*2+1, mid, ne);
	}
};

int main(){
	int N;
	scanf("%d", &N);
	P up[MAX];
	SegTree ST(N);
	for(int i=0; i<N; i++){
		int val;
		scanf("%d", &val);
		up[i] = P(val, i);
	}
	sort(up, up+N);

	long long result = 0;
	for(int i=0; i<N; i++){
		int val;
		scanf("%d", &val);
		int index = lower_bound(up, up+N, P(val, -1))->second;
		result += ST.sum(index, N);
		ST.inc(index);
	}
	printf("%lld\n", result);
}