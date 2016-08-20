#include <cstdio>
#include <algorithm>
using namespace std;
 
int N, P[1000];
bool visited[1000];
 
void dfs(int curr){
    visited[curr] = true;
    if(!visited[P[curr]]) dfs(P[curr]);
}
 
int main(){
    int T;
    scanf("%d", &T);
    for(int t=0; t<T; t++){
        scanf("%d", &N);
        for(int i=0; i<N; i++){
            scanf("%d", P+i);
            P[i]--;
        }
         
        int result = 0;
        fill(visited, visited+N, false);
        for(int i=0; i<N; i++){
            if(!visited[i]){
                result++;
                dfs(i);
            }
        }
        printf("%d\n", result);
    }
}