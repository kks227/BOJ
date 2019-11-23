#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 100000;
const int MAX_ST = 1<<18;
const int INF = 1e9;
typedef pair<int, int> P;

struct SegTree{
	P A[MAX_ST];
	SegTree(){ fill(A, A+MAX_ST, P(INF, -1)); }
	void construct(){
		for(int i = MAX_ST/2-1; i > 0; --i)
			A[i] = min(A[i*2], A[i*2+1]);
	}
	P getMin(int s, int e){ return getMin(s, e, 1, 0, MAX_ST/2); }
	P getMin(int s, int e, int node, int ns, int ne){
		if(ne <= s || e <= ns) return P(INF, -1);
		if(s <= ns && ne <= e) return A[node];
		int mid = (ns+ne)/2;
		return min(getMin(s, e, node*2, ns, mid), getMin(s, e, node*2+1, mid, ne));
	}
};

int N, A[MAX];
long long pSum[MAX+1];
SegTree ST;

long long rain(int s, int e, int k){
	if(s == e) return -1;
	if(k == 1) return 0;
	if(s+1 == e) return -1;
	int m1 = ST.getMin(s, e).second;
	long long temp = rain(s, m1, k);
	if(temp >= 0) return temp;
	int m2 = m1+1;
	for(; A[m1] == A[m2] && m2 < e; ++m2);
	if(m2 == e) return -1;
	temp = rain(m2, e, k-(m1!=s));
	if(temp == -1) return -1;
	return pSum[m1] - pSum[s] - 1LL*(m1-s)*A[m1] + temp;
}

int main(){
	int K;
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N; ++i){
		scanf("%d", A+i);
		pSum[i+1] = pSum[i] + A[i];
		ST.A[MAX_ST/2 + i] = P(A[i], i);
	}
	ST.construct();
	long long result = rain(0, N, K);
	printf("%lld\n", result);
}