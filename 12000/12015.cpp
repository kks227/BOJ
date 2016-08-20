#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int ST_MAX = 2097152;

struct SegTree{
	int A[ST_MAX], start;
	SegTree(){
		fill(A, A+ST_MAX, 0);
		start = ST_MAX/2;
	}
	void update(int n, int k){
		n += start;
		A[n] = k;
		while(n > 1){
			n /= 2;
			A[n] = max(A[n*2], A[n*2+1]);
		}
	}
	long long largest(int s, int e){
		return largest(s, e, 1, 0, start);
	}
	long long largest(int s, int e, int node, int ns, int ne){
		if(ne <= s || e <= ns) return 0;
		if(s <= ns && ne <= e) return A[node];
		int mid = (ns+ne)/2;
		return max(largest(s, e, node*2, ns, mid), largest(s, e, node*2+1, mid, ne));
	}
};

int main(){
	int N;
	P s[1000000];
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int A;
		scanf("%d", &A);
		s[i] = P(A, i);
	}
	sort(s, s+N, [](const P &p, const P &q){
		if(p.first != q.first) return p.first < q.first;
		return p.second > q.second;
	});

	SegTree ST;
	int result = 0;
	for(int i=0; i<N; i++){
		int temp = ST.largest(0, s[i].second) + 1;
		result = max(result, temp);
		ST.update(s[i].second, temp);
	}
	printf("%d\n", result);
}