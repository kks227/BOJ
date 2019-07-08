#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 1000001;
const int MAX_D = 21;
const int MAX_ST = 1<<21;

struct SegTree{
    int A[MAX_ST];
    SegTree(){ fill(A, A+MAX_ST, 0); }

    void add(int n, int k){
        n += MAX_ST/2;
        do{
            A[n] += k;
            n /= 2;
        }while(n > 1);
    }
    int sum(int s, int e){ return sum(s, e, 1, 0, MAX_ST/2); }
    int sum(int s, int e, int node, int ns, int ne){
        if(e <= ns || ne <= s) return 0;
        if(s <= ns && ne <= e) return A[node];
        int mid = (ns+ne)/2;
        return sum(s, e, node*2, ns, mid) + sum(s, e, node*2+1, mid, ne);
    }
};

class Pokegene{
public:
    Pokegene(){
        N = 1;
        memset(go, -1, sizeof(go));
        fill(wordNum, wordNum+MAX, -1);
    }

    void insert(int curr, char *s, int n){
        char c = *s;
        if(c == '\0'){
            wordNum[curr] = n;
            return;
        }
        int i = c - 'a';
        if(go[curr][i] < 0) go[curr][i] = N++;
        insert(go[curr][i], s+1, n);
    }

    void construct(){
        tempCnt = 0;
        fill(L, L+MAX, -1);
        fill(R, R+MAX, -1);
        memset(parent, -1, sizeof(parent));
        construct(0, 0);

        for(int j = 0; j < MAX_D-1; ++j)
            for(int i = 1; i < N; ++i)
                if(parent[i][j] != -1) parent[i][j+1] = parent[ parent[i][j] ][j];
    }

    int solve(int *A, int K, int G){
        int B[MAX];
        for(int i = 0; i < K; ++i){
            B[i] = nodeNum[A[i]];
            ST.add(B[i], 1);
        }
        sort(B, B+K);

        int result = 0;
        for(int i = 0; i+G <= K; ++i){
            int u = B[i], v = B[i+G-1], w = LCA(u, v);
            if(ST.sum(L[w], R[w]+1) > G) continue;

            int lo = 0, hi = w;
            for(int j = MAX_D-1; j >= 0; --j){
                int next = parent[hi][j];
                if(next == -1) continue;
                (ST.sum(L[next], R[next]+1) > G ? lo : hi) = next;
            }
            result += depth[w] - depth[lo];
        }

        for(int i = 0; i < K; ++i)
            ST.add(B[i], -1);

        return result;
    }

private:
    int N, wordNum[MAX], go[MAX][26]; // root is 0
    int tempCnt, nodeNum[MAX], label[MAX], L[MAX], R[MAX];
    int parent[MAX][MAX_D], depth[MAX];
    SegTree ST;

    void construct(int curr, int d){
        label[curr] = tempCnt++;
        int &cl = label[curr];
        L[cl] = R[cl] = cl;
        depth[cl] = d;
        if(wordNum[curr] >= 0) nodeNum[wordNum[curr]] = cl;

        for(int i = 0; i < 26; ++i){
            int next = go[curr][i];
            if(next == -1) continue;

            construct(next, d+1);
            int &nl = label[next];
            parent[nl][0] = cl;
            R[cl] = R[nl];
        }
    }

    int LCA(int u, int v){
        if(depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];

        for(int j = 0; diff; ++j){
            if(diff % 2) u = parent[u][j];
            diff /= 2;
        }

        if(u != v){
            for(int j = MAX_D-1; j >= 0; --j){
                if(parent[u][j] != -1 && parent[u][j] != parent[v][j]){
                    u = parent[u][j];
                    v = parent[v][j];
                }
            }
            u = parent[u][0];
        }
        return u;
    }
};



int main(){
    Pokegene solver;
    int N, Q;
    scanf("%d %d", &N, &Q);
    for(int i = 0; i < N; ++i){
        char S[MAX];
        scanf("%s", S);
        solver.insert(0, S, i);
    }
    solver.construct();
    for(int i = 0; i < Q; ++i){
        int K, L, A[MAX];
        scanf("%d %d", &K, &L);
        for(int j = 0; j < K; ++j){
            scanf("%d", A+j);
            --A[j];
        }
        printf("%d\n", solver.solve(A, K, L));
    }
}