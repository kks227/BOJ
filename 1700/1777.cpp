#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 1<<18;

struct SegTree{
	int arr[MAX], start;
	SegTree(int n): start(MAX/2){
		fill(arr, arr+MAX, 0);
		fill(arr+start, arr+start+n, 1);
		for(int i=start-1; i>0; i--)
			arr[i] = arr[i*2] + arr[i*2+1];
	}
	void update(int n, int k){
		n += start;
		arr[n] = k;
		while(n > 1){
			n /= 2;
			arr[n] = arr[n*2] + arr[n*2+1];
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
	int N, S[100000], I[100000];
	scanf("%d", &N);
	SegTree ST(N);
	for(int i=0; i<N; i++)
		scanf("%d", I+i);
	for(int i=N-1; i>=0; i--){
		int lo = 0, hi = N;
		while(lo+1 < hi){
			int mid = (lo+hi)/2;
			(ST.sum(mid, N) <= I[i] ? hi : lo) = mid;
		}
		S[lo] = i+1;
		ST.update(lo, 0);
	}
	for(int i=0; i<N; i++)
		printf("%d ", S[i]);
}