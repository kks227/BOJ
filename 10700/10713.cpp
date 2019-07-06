#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 100000;
const int MAX_ST = 1<<18;

struct SegTree{
    long long arr[MAX_ST], lazy[MAX_ST];
    SegTree(){
        fill(arr, arr+MAX_ST, 0);
        fill(lazy, lazy+MAX_ST, 0);
    }
    void construct(){
        for(int i = MAX_ST/2-1; i > 0; --i)
            arr[i] = arr[i*2] + arr[i*2+1];
    }
    void propagate(int node, int ns, int ne){
        if(lazy[node] != 0){
            if(node < MAX_ST/2){
                lazy[node*2] += lazy[node];
                lazy[node*2+1] += lazy[node];
            }
            arr[node] += lazy[node] * (ne-ns);
            lazy[node] = 0;
        }
    }
    void add(int s, int e, int k){ add(s, e, k, 1, 0, MAX_ST/2); }
    void add(int s, int e, int k, int node, int ns, int ne){
        propagate(node, ns, ne);
        if(e <= ns || ne <= s) return;
        if(s <= ns && ne <= e){
            lazy[node] += k;
            propagate(node, ns, ne);
            return;
        }
        int mid = (ns+ne)/2;
        add(s, e, k, node*2, ns, mid);
        add(s, e, k, node*2+1, mid, ne);
        arr[node] = arr[node*2] + arr[node*2+1];
    }
    long long sum(int s, int e){ return sum(s, e, 1, 0, MAX_ST/2); }
    long long sum(int s, int e, int node, int ns, int ne){
        propagate(node, ns, ne);
        if(e <= ns || ne <= s) return 0;
        if(s <= ns && ne <= e) return arr[node];
        int mid = (ns+ne)/2;
        return sum(s, e, node*2, ns, mid) + sum(s, e, node*2+1, mid, ne);
    }
};



int main(){
    int N, M, p1, p2;
    scanf("%d %d", &N, &M);
    SegTree ST;
    for(int i = 0; i < M; ++i){
        scanf("%d", &p2);
        --p2;
        if(i > 0) ST.add(min(p1, p2), max(p1, p2), 1);
        p1 = p2;
    }
    long long result = 0;
    for(int i = 0; i < N-1; ++i){
        int A, B, C;
        scanf("%d %d %d", &A, &B, &C);
        long long k = ST.sum(i, i+1);
        result += min(A*k, B*k + C);
    }
    printf("%lld\n", result);
}