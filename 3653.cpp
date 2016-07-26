#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 200000;
const int ST_MAX = 524288;

struct SegTree{
	int size, start;
	int arr[ST_MAX];
	SegTree(int n){
		size = n;
		start = 1;
		while(start < size) start *= 2;
		memset(arr, 0, sizeof(arr));
	}
	void add(int i, int val){
		i += start;
		while(i > 0){
			arr[i] += val;
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
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N, M, index[100000];
		scanf("%d %d", &N, &M);
		SegTree ST(N+M);
		for(int i=0; i<N; i++){
			index[i] = N-i-1;
			ST.add(index[i], 1);
		}
		for(int i=0; i<M; i++){
			int val;
			scanf("%d", &val);
			val--;
			printf("%d ", ST.sum(index[val]+1, N+M));
			ST.add(index[val], -1);
			index[val] = N+i;
			ST.add(index[val], 1);
		}
		puts("");
	}
}