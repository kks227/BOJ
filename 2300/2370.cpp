#include <cstdio>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int MAX = 10000;
const int MAX_ST = 1<<16;

struct SegTree{
    int arr[MAX_ST], lazy[MAX_ST];
    SegTree(){
        fill(arr, arr+MAX_ST, 0);
        fill(lazy, lazy+MAX_ST, 0);
    }
    void propagate(int node, int ns, int ne){
        if(lazy[node] != 0){
            if(node >= MAX_ST/2) arr[node] = lazy[node];
            else lazy[node*2] = lazy[node*2+1] = lazy[node];
            lazy[node] = 0;
        }
    }
    void update(int s, int e, int k){ update(s, e, k, 1, 0, MAX_ST/2); }
    void update(int s, int e, int k, int node, int ns, int ne){
        propagate(node, ns, ne);
        if(e <= ns || ne <= s) return;
        if(s <= ns && ne <= e){
            lazy[node] = k;
            propagate(node, ns, ne);
            return;
        }
        int mid = (ns+ne)/2;
        update(s, e, k, node*2, ns, mid);
        update(s, e, k, node*2+1, mid, ne);
    }
    int get(int k){ return get(k, 1, 0, MAX_ST/2); }
    int get(int k, int node, int ns, int ne){
        propagate(node, ns, ne);
        if(k < ns || ne <= k) return 0;
        if(ns+1 == ne) return arr[node];
        int mid = (ns+ne)/2;
        return max(get(k, node*2, ns, mid), get(k, node*2+1, mid, ne));
    }
};

int main(){
    int N, s[MAX], e[MAX];
    scanf("%d", &N);
    set<int> S;
    for(int i = 0; i < N; ++i){
        scanf("%d %d", s+i, e+i);
        S.insert(s[i]);
        S.insert(++e[i]);
    }
    int K = 0;
    unordered_map<int, int> H;
    for(int i: S)
        H[i] = K++;
    SegTree ST;
    for(int i = 0; i < N; ++i)
        ST.update(H[s[i]], H[e[i]], i+1);

    set<int> result;
    for(int i = 0; i < K; ++i)
        result.insert(ST.get(i));
    result.erase(0);
    printf("%d\n", result.size());
}