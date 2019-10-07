#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAX = 50000;

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
	int N, A[MAX*2], pos[MAX];
	QueryNode Q[MAX];
	scanf("%d", &N);
	fill(pos, pos+N, -1);
	for(int i = 0; i < N*2; ++i){
		scanf("%d", A+i);
		if(pos[--A[i]] != -1) Q[A[i]] = QueryNode(pos[A[i]], i+1, A[i]);
		else pos[A[i]] = i;
	}
	sqrtN = sqrt(N*2);
	sort(Q, Q+N);

	int dcnt = 0, cnt[MAX] = {0}, s = Q[0].s, e = Q[0].e;
	long long result = 0;
	for(int i = s; i < e; ++i){
		if(cnt[A[i]]++ == 1) --dcnt;
		else if(cnt[A[i]] == 1) ++dcnt;
	}
	result += dcnt;
	for(int i = 1; i < N; ++i){
		while(Q[i].s < s){
			int k = A[--s];
			if(cnt[k]++ == 1) --dcnt;
			else if(cnt[k] == 1) ++dcnt;
		}
		while(e < Q[i].e){
			int k = A[e++];
			if(cnt[k]++ == 1) --dcnt;
			else if(cnt[k] == 1) ++dcnt;
		}
		while(Q[i].s > s){
			int k = A[s++];
			if(cnt[k]-- == 1) --dcnt;
			else if(cnt[k] == 1) ++dcnt;
		}
		while(e > Q[i].e){
			int k = A[--e];
			if(cnt[k]-- == 1) --dcnt;
			else if(cnt[k] == 1) ++dcnt;
		}
		result += dcnt;
	}
	printf("%lld\n", result/2);
}