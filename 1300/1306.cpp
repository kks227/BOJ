#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 1<<21;

struct SegTree{
	int arr[MAX], start;
	SegTree(): start(MAX/2){ fill(arr, arr+MAX, 0); }
	void construct(){
		for(int i=start-1; i>0; i--)
			arr[i] = max(arr[i*2], arr[i*2+1]);
	}
	int maxn(int s, int e){ return maxn(s, e, 1, 0, start); }
	int maxn(int s, int e, int node, int ns, int ne){
		if(e <= ns || ne <= s) return 0;
		if(s <= ns && ne <= e) return arr[node];
		int mid = (ns+ne)/2;
		return max(maxn(s, e, node*2, ns, mid), maxn(s, e, node*2+1, mid, ne));
	}
};

int main(){
	SegTree ST;
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++)
		scanf("%d", ST.arr+ST.start+i);
	ST.construct();
	for(int i=M-1; i<N-M+1; i++)
		printf("%d ", ST.maxn(i-M+1, i+M));
}