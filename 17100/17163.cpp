#include <cstdio>
#include <list>
#include <algorithm>
using namespace std;
const int MAX = 1000000;
const int MAX_ST = 1<<21;
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
    int Q, M, A[MAX], pos = 0;
    scanf("%d %d", &Q, &M);
    if(M > MAX){
        for(int i = 0; i < Q; ++i){
            int o, dummy;
            scanf("%d", &o);
            if(o == 1) scanf("%d", &dummy);
            else if(o == 3) puts("-1");
        }
        return 0;
    }

    list<int> S[MAX];
    SegTree ST;
    for(int i = 0; i < Q; ++i){
        int o, k;
        scanf("%d", &o);
        if(o == 1){
            scanf("%d", A+pos);
            k = A[pos] %= M;
            S[k].push_back(pos);
            ST.update(k, pos++);
        }
        else if(o == 2){
            if(pos > 0){
                k = A[--pos];
                S[k].pop_back();
                ST.update(k, S[k].empty() ? -1 : S[k].back());
            }
        }
        else{
            int result = ST.getMin(0, M);
            if(result >= 0) result = pos - result;
            printf("%d\n", result);
        }
    }
}