#include <cstdio>
#include <vector>
using namespace std;
const int MAX = 50;

int main(){
    int N, M;
    bool adj[MAX][MAX] = {false,};
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; ++i){
        int u, v;
        scanf("%d %d", &u, &v);
        --u; --v;
        adj[u][v] = adj[v][u] = true;
    }

    vector<int> result;
    while(M < N*(N-1)/2){
        bool temp[MAX][MAX] = {false,};
        for(int k = 0; k < N; ++k)
            for(int i = 0; i < N; ++i)
                for(int j = i+1; j < N; ++j)
                    if(adj[i][k] && adj[k][j] && !temp[i][j]) temp[i][j] = true;

        int cnt = 0;
        for(int i = 0; i < N; ++i){
            for(int j = i+1; j < N; ++j){
                if(temp[i][j] && !adj[i][j]){
                    adj[i][j] = adj[j][i] = true;
                    ++cnt;
                }
            }
        }
        result.push_back(cnt);
        M += cnt;
    }
    printf("%d\n", result.size());
    for(int i: result)
        printf("%d\n", i);
}