#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 200000;
const int MAX_ST = 1<<19;
const int INF = 1e9;

struct SegTree{
    int A[MAX_ST];
    SegTree(){ fill(A, A+MAX_ST, 0); }
    void add(int n){
        n += MAX_ST/2;
        ++A[n];
        while(n > 1){
            n /= 2;
            ++A[n];
        }
    }
    int sum(int s, int e){ return sum(s, e, 1, 0, MAX_ST/2); }
    int sum(int s, int e, int node, int ns, int ne){
        if(e <= ns || ne <= s) return 0;
        if(s <= ns && ne <= e) return A[node];
        int mid = (ns+ne)/2;
        return sum(s, e, node*2, ns, mid) + sum(s, e, node*2+1, mid, ne);
    }
    int cnt(int k){
        if(A[1] < k) return INF;
        int lo = 0, hi = MAX;
        while(lo+1 < hi){
            int mid = (lo+hi)/2;
            (sum(0, mid+1) >= k ? hi : lo) = mid;
        }
        return hi;
    }
};

int main(){
    int K, a[MAX], pMax[MAX], r1 = -1, r2 = -1;
    scanf("%d", &K);
    for(int i = 0; i < K; ++i){
        scanf("%d", a+i);
        pMax[i] = max((i > 0 ? pMax[i-1] : 0), a[i]);
    }
    SegTree ST;
    ST.add(a[K-1]);
    ST.add(a[K-2]);
    for(int i = K-3; i > 0; --i){
        int M = a[i], N = pMax[i-1];
        if(ST.cnt(2*M) <= N){
            if(r1 < N || r1 == N && r2 < M){
                r1 = N;
                r2 = M;
            }
        }
        ST.add(a[i]);
    }
    if(r1 < 0) puts("-1");
    else printf("%d %d\n", r1, r2);
}