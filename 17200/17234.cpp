#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 501;

int main(){
    int N, A, B;
    bool visited[MAX/10][MAX][MAX] = {true,};
    scanf("%d %d %d", &N, &A, &B);
    queue<int> Q;
    Q.push(0);
    for(int result = 1; ; ++result){
        int qSize = Q.size();
        for(int i = 0; i < qSize; ++i){
            int ct = Q.front() / (MAX*MAX);
            int t = Q.front() % (MAX*MAX) / MAX;
            int curr = Q.front() % MAX;
            Q.pop();

            int nt = t + 1, next = curr + A;
            if(N <= next){
                printf("%d\n", result);
                return 0;
            }
            if(!visited[ct][nt][next]){
                visited[ct][nt][next] = true;
                Q.push(ct*MAX*MAX + nt*MAX + next);
            }

            next = curr + B;
            if(!visited[ct][nt][next]){
                visited[ct][nt][next] = true;
                Q.push(ct*MAX*MAX + nt*MAX + next);
            }

            ++ct;
            if(ct*10 > nt) continue;
            next = curr*2;
            if(N <= next && next < N+A){
                printf("%d\n", result);
                return 0;
            }
            if(next < N && !visited[ct][nt][next]){
                visited[ct][nt][next] = true;
                Q.push(ct*MAX*MAX + nt*MAX + next);
            }
        }
    }
}