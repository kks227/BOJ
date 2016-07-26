#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
 
vector<int> adj[1000000];
bool visited[1000000];
int cache[1000000][2];
 
int minCnt(int root, bool pt){
    int &ret = cache[root][pt];
    int result = 1, result2 = 0;
    for(vector<int>::iterator iter=adj[root].begin(); iter!=adj[root].end(); iter++){
        if(visited[*iter]) continue;
        if(cache[*iter][1] != -1) result += cache[*iter][1];
        else{
            visited[root] = true;
            result += minCnt(*iter, true);
            visited[root] = false;
        }
        if(cache[*iter][0] != -1) result2 += cache[*iter][0];
        else{
            visited[root] = true;
            result2 += minCnt(*iter, false);
            visited[root] = false;
        }
    }
    if(!pt) return ret = result;
    return ret = (result<result2)?result:result2;
}
 
int main(){
 
    int N, u, v;
    scanf("%d", &N);
    for(int i=0; i<N-1; i++){
        scanf("%d %d", &u, &v);
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    memset(cache, -1, sizeof(int)*1000000*2);
    visited[0] = true;
    printf("%d\n", minCnt(0, true));
 
    return 0;
}