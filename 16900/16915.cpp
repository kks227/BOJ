#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_N = 100000;
const int MAX = MAX_N*2;

inline int oppo(int n){ return n/2*2 + !(n%2); }

int dfsn[MAX], dcnt, SN, sn[MAX];
vector<int> adj[MAX];
stack<int> S;
bool finished[MAX];

int dfs(int curr){
    int result = dfsn[curr] = ++dcnt;
    S.push(curr);
    for(int next: adj[curr]){
        if(dfsn[next] < 0) result = min(result, dfs(next));
        else if(!finished[next]) result = min(result, dfsn[next]);
    }
    if(result == dfsn[curr]){
        while(1){
            int temp = S.top(); S.pop();
            sn[temp] = SN;
            finished[temp] = true;
            if(temp == curr) break;
        }
        ++SN;
    }
    return result;
}

int main(){
    int N, M, t[MAX_N], s[MAX_N][2], scnt[MAX_N] = {0,};
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; ++i)
        scanf("%d", t+i);
    for(int i = 0; i < M; ++i){
        int K;
        scanf("%d", &K);
        for(int j = 0; j < K; ++j){
            int k;
            scanf("%d", &k);
            --k;
            s[k][scnt[k]++] = i;
        }
    }

    for(int i = 0; i < N; ++i){
        int a = s[i][0]*2 + 1, b = s[i][1]*2 + 1;
        if(t[i] == 0){ // a xor b => (!a or !b) and (a or b)
            adj[a].push_back(oppo(b));
            adj[b].push_back(oppo(a));
            adj[oppo(a)].push_back(b);
            adj[oppo(b)].push_back(a);
        }
        else{ // a = b => (a or !b) and (!a or b)
            adj[oppo(a)].push_back(oppo(b));
            adj[b].push_back(a);
            adj[a].push_back(b);
            adj[oppo(b)].push_back(oppo(a));
        }
    }

    fill(dfsn, dfsn+MAX, -1);
    for(int i = 0; i < MAX; ++i)
        if(dfsn[i] < 0) dfs(i);

    int result = 1;
    for(int i = 0; i < M; ++i){
        if(sn[i*2] == sn[i*2+1]){
            result = 0;
            break;
        }
    }
    printf("%d\n", result);
}