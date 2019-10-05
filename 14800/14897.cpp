#include <cstdio>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int MAX = 1000000;

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
	int N, M, A[MAX], K = 0;
	unordered_set<int> S;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%d", A+i);
		S.insert(A[i]);
	}
	unordered_map<int, int> H;
	for(int i: S)
		H[i] = K++;
	for(int i = 0; i < N; ++i)
		A[i] = H[A[i]];
	sqrtN = sqrt(N);

	QueryNode Q[MAX];
	scanf("%d", &M);
	for(int i = 0; i < M; ++i){
		int l, r;
		scanf("%d %d", &l, &r);
		Q[i] = QueryNode(l-1, r, i);
	}
	sort(Q, Q+M);

	int dcnt = 0, cnt[MAX+1] = {0}, result[MAX];
	int s = Q[0].s, e = Q[0].e;
	for(int i = s; i < e; ++i)
		if(cnt[A[i]]++ == 0) ++dcnt;
	result[Q[0].n] = dcnt;
	for(int i = 1; i < M; ++i){
		while(Q[i].s < s) if(cnt[A[--s]]++ == 0) ++dcnt;
		while(e < Q[i].e) if(cnt[A[e++]]++ == 0) ++dcnt;
		while(Q[i].s > s) if(--cnt[A[s++]] == 0) --dcnt;
		while(e > Q[i].e) if(--cnt[A[--e]] == 0) --dcnt;
		result[Q[i].n] = dcnt;
	}
	for(int i = 0; i < M; ++i)
		printf("%d\n", result[i]);
}