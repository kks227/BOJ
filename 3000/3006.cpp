#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int ST_MAX = 262144;

struct SegTree{
	int A[ST_MAX], start;
	SegTree(){
		fill(A, A+ST_MAX, 0);
		start = ST_MAX/2;
	}
	void update(int n){
		n += start;
		A[n]++;
		while(n > 1){
			n /= 2;
			A[n]++;
		}
	}
	int cnt(int s, int e){
		return cnt(s, e, 1, 0, start);
	}
	int cnt(int s, int e, int node, int ns, int ne){
		if(ne <= s || e <= ns) return 0;
		if(s <= ns && ne <= e) return A[node];
		int mid = (ns+ne)/2;
		return cnt(s, e, node*2, ns, mid) + cnt(s, e, node*2+1, mid, ne);
	}
};

int main(){
	int N;
	scanf("%d", &N);
	P p[100000];
	for(int i=0; i<N; i++){
		int val;
		scanf("%d", &val);
		p[i] = P(val-1, i);
	}
	sort(p, p+N);

	SegTree ST;
	for(int i=0; i<N; i++){
		int pos;
		if(i%2){
			pos = p[N-1-i/2].second;
			printf("%d\n", N-1-pos - ST.cnt(pos, N));
		}
		else{
			pos = p[i/2].second;
			printf("%d\n", pos - ST.cnt(0, pos));
		}
		ST.update(pos);
	}
}