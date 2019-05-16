#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 100000;

int main(){
    int N, K = 1, prev, p[MAX];
    bool visited[MAX] = {false,};
    scanf("%d %d", &N, &prev);
    p[prev] = -1;
    visited[prev] = true;
    for(int i = 1; i < N; ++i){
        int curr;
        scanf("%d", &curr);
        if(!visited[curr]){
            visited[curr] = true;
            p[curr] = prev;
            K = max(curr+1, K);
        }
        prev = curr;
    }
    printf("%d\n", K);
    for(int i = 0; i < K; ++i)
        printf("%d ", p[i]);
}