#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAX = 100000;
const int MAX_VAL = 1000000;

int sqrtN;

struct QueryNode{
	int s, e, n;
	QueryNode(): QueryNode(0, 0, -1){}
	QueryNode(int s1, int e1, int n1): s(s1), e(e1), n(n1){}
	bool operator <(const QueryNode &O)const{
		if(s/sqrtN != O.s/sqrtN) return (s/sqrtN < O.s/sqrtN);
		return (e < O.e);
	}
};

int main(){
	int N, M, A[MAX], vcnt = 0;
	QueryNode Q[MAX];
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; ++i)
		scanf("%d", A+i);
	sqrtN = sqrt(N);
	for(int i = 0; i < M; ++i){
		int l, r;
		scanf("%d %d", &l, &r);
		Q[i] = QueryNode(l-1, r, i);
	}
	sort(Q, Q+M);

	int cnt[MAX_VAL+1] = {0}, s = Q[0].s, e = Q[0].e;
	long long sum = 0, result[MAX];
	for(int i = s; i < e; ++i) ++cnt[A[i]];
	for(int i = 1; i <= MAX_VAL; ++i)
		sum += 1LL*cnt[i]*cnt[i]*i;
	result[Q[0].n] = sum;
	for(int i = 1; i < M; ++i){
		while(Q[i].s < s){
			int k = A[--s];
			sum -= 1LL*cnt[k]*cnt[k]*k;
			++cnt[k];
			sum += 1LL*cnt[k]*cnt[k]*k;
		}
		while(e < Q[i].e){
			int k = A[e++];
			sum -= 1LL*cnt[k]*cnt[k]*k;
			++cnt[k];
			sum += 1LL*cnt[k]*cnt[k]*k;
		}
		while(Q[i].s > s){
			int k = A[s++];
			sum -= 1LL*cnt[k]*cnt[k]*k;
			--cnt[k];
			sum += 1LL*cnt[k]*cnt[k]*k;
		}
		while(e > Q[i].e){
			int k = A[--e];
			sum -= 1LL*cnt[k]*cnt[k]*k;
			--cnt[k];
			sum += 1LL*cnt[k]*cnt[k]*k;
		}
		result[Q[i].n] = sum;
	}
	for(int i = 0; i < M; ++i)
		printf("%lld\n", result[i]);
}