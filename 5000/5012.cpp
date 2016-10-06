#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 1<<18;

struct SegTree{
	int arr[MAX], start;
	SegTree(): start(MAX/2){ fill(arr, arr+MAX, 0); }
	void clear(){ fill(arr, arr+MAX, 0); }
	void inc(int n){
		n += start;
		arr[n]++;
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
	int N, A[100000], G[100000], L[100000];
	scanf("%d", &N);
	SegTree ST;
	for(int i=0; i<N; i++){
		scanf("%d", A+i);
		A[i]--;
		G[i] = ST.sum(A[i]+1, N);
		ST.inc(A[i]);
	}
	ST.clear();
	for(int i=N-1; i>=0; i--){
		L[i] = ST.sum(0, A[i]);
		ST.inc(A[i]);
	}
	long long result = 0;
	for(int i=0; i<N; i++)
		result += 1LL * G[i] * L[i];
	printf("%lld\n", result);
}