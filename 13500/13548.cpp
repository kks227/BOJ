#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAX = 100000;

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
    int N, M, A[MAX];
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%d", A+i);
    sqrtN = sqrt(N);

    QueryNode Q[MAX];
    scanf("%d", &M);
    for(int i = 0; i < M; ++i){
        int l, r;
        scanf("%d %d", &l, &r);
        Q[i] = QueryNode(l-1, r, i);
    }
    sort(Q, Q+M);

    int mcnt = 0, cnt[MAX+1] = {0,}, rcnt[MAX+1] = {0,}, result[MAX];
    int s = Q[0].s, e = Q[0].e;
    for(int i = s; i < e; ++i){
        int temp = ++cnt[A[i]];
        ++rcnt[temp];
        if(temp > mcnt) ++mcnt;
    }
    result[Q[0].n] = mcnt;
    for(int i = 1; i < M; ++i){
        while(Q[i].s < s){
            int temp = ++cnt[A[--s]];
            ++rcnt[temp];
            if(temp > mcnt) ++mcnt;
        }
        while(e < Q[i].e){
            int temp = ++cnt[A[e++]];
            ++rcnt[temp];
            if(temp > mcnt) ++mcnt;
        }
        while(Q[i].s > s){
            int temp = cnt[A[s++]]--;
            if(--rcnt[temp] == 0 && temp == mcnt) --mcnt;
        }
        while(e > Q[i].e){
            int temp = cnt[A[--e]]--;
            if(--rcnt[temp] == 0 && temp == mcnt) --mcnt;
        }
        result[Q[i].n] = mcnt;
    }
    for(int i = 0; i < M; ++i)
        printf("%d\n", result[i]);
}