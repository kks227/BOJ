#include <cstdio>
#include <cmath>
#include <tuple>
#include <algorithm>
using namespace std;
typedef tuple<int, int, int, int> Query; // L/sqrt(N), R, L, q_n

int main(){
	int N, M, A[100000], result[100000];
	Query Q[100000];
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", A+i);
	scanf("%d", &M);
	double sqrtN = sqrt(N);
	for(int i=0; i<M; i++){
		int l, r;
		scanf("%d %d", &l, &r);
		l--; r--;
		Q[i] = Query(l/sqrtN, r, l, i);
	}
	sort(Q, Q+M);

	int dcnt = 0, cnt[1000001] = {0}, l = get<2>(Q[0]), r = get<1>(Q[0]);
	for(int i=l; i<=r; i++)
		if(cnt[A[i]]++ == 0) dcnt++;
	result[get<3>(Q[0])] = dcnt;
	for(int i=1; i<M; i++){
		int nl, nr, qi, dummy;
		tie(dummy, nr, nl, qi) = Q[i];
		while(nl < l) if(cnt[A[--l]]++ == 0) dcnt++;
		while(r < nr) if(cnt[A[++r]]++ == 0) dcnt++;
		while(nl > l) if(--cnt[A[l++]] == 0) dcnt--;
		while(r > nr) if(--cnt[A[r--]] == 0) dcnt--;
		result[qi] = dcnt;
	}
	for(int i=0; i<M; i++)
		printf("%d\n", result[i]);
}