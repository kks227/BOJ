#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;
const int MAX = 100;
const int MAX_N = 200000;
const int MAX_ST = 1<<8;
const int INF = 1e9;

struct SegTree{
    int A[MAX_ST];
    SegTree(){ fill(A, A+MAX_ST, -1); }
    void update(int n, int k){
        n += MAX_ST/2;
        A[n] = k;
        while(n > 1){
            n /= 2;
            A[n] = min(A[n*2], A[n*2+1]);
        }
    }
    int getMin(int s, int e){ return getMin(s, e, 1, 0, MAX_ST/2); }
    int getMin(int s, int e, int node, int ns, int ne){
        if(e <= ns || ne <= s) return INF;
        if(s <= ns && ne <= e) return A[node];
        int mid = (ns+ne)/2;
        return min(getMin(s, e, node*2, ns, mid), getMin(s, e, node*2+1, mid, ne));
    }
};

int main(){
    int Q, M, A[MAX_N], pos = 0;
    stack<int> S[MAX];
    SegTree ST;
    scanf("%d %d", &Q, &M);
    for(int i = 0; i < Q; ++i){
        int o, k;
        scanf("%d", &o);
        if(o == 1){
            scanf("%d", A+pos);
            k = A[pos] %= M;
            S[k].push(pos);
            ST.update(k, pos++);
        }
        else if(o == 2){
            if(pos > 0){
                k = A[--pos];
                S[k].pop();
                ST.update(k, S[k].empty() ? -1 : S[k].top());
            }
        }
        else{
            int result = ST.getMin(0, M);
            if(result >= 0) result = pos - result;
            printf("%d\n", result);
        }
    }
}