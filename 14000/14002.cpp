#include <cstdio>
#include <utility>
#include <stack>
#include <algorithm>
using namespace std;
const int MAX_ST = 1<<11;
const int MAX = 1e3;
typedef pair<int, int> P;

struct SegTree{
    int A[MAX_ST];
    SegTree(){ fill(A, A+MAX_ST, 0); }
    void update(int n, int k){
        n += MAX_ST/2;
        A[n] = k;
        while(n > 1){
            n /= 2;
            A[n] = max(A[n*2], A[n*2+1]);
        }
    }
    int getMax(int p, int e){ return getMax(p, e, 1, 0, MAX_ST/2); }
    int getMax(int p, int e, int node, int ns, int ne){
        if(ne <= p || e <= ns) return 0;
        if(p <= ns && ne <= e) return A[node];
        int mid = (ns+ne)/2;
        return max(getMax(p, e, node*2, ns, mid), getMax(p, e, node*2+1, mid, ne));
    }
};

int main(){
    int N, A[MAX];
    P p[MAX];
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        scanf("%d", A+i);
        p[i] = P(A[i], i);
    }
    sort(p, p+N, [](const P &p, const P &q){
        if(p.first != q.first) return p.first < q.first;
        return p.second > q.second;
    });

    SegTree ST;
    int result = 0;
    for(int i = 0; i < N; ++i){
        int temp = ST.getMax(0, p[i].second) + 1;
        result = max(result, temp);
        ST.update(p[i].second, temp);
    }
    printf("%d\n", result);
    
    stack<int> S;
    for(int i = result, j = N-1; i > 0; --i){
        while(ST.A[MAX_ST/2 + j] != i) --j;
        S.push(A[j]);
    }
    while(!S.empty()){
        printf("%d ", S.top());
        S.pop();
    }
}