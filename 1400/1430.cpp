#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 101;

int main(){
    int N, R, D, x[MAX], y[MAX];
    vector<int> adj[MAX];
    scanf("%d %d %d %d %d", &N, &R, &D, x, y);
    for(int i = 1; i <= N; ++i){
        scanf("%d %d", x+i, y+i);
        for(int j = 0; j < i; ++j){
            if((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) <= R*R){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    double result = 0;
    queue<int> Q;
    bool visited[MAX] = {true,};
    Q.push(0);
    for(double factor = 1; !Q.empty(); factor /= 2){
        int qSize = Q.size();
        for(int i = 0; i < qSize; ++i){
            int curr = Q.front(); Q.pop();
            for(int next: adj[curr]){
                if(!visited[next]){
                    visited[next] = true;
                    Q.push(next);
                    if(next > 0) result += D*factor;
                }
            }
        }
    }
    printf("%.2lf\n", round(result*100)/100);
}