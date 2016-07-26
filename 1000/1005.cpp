// [TopologicalSort]

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
 
int main(){
    int T;
    scanf("%d", &T);
    for(int t=0; t<T; t++){
        int N, K, W, time[1000], pre[1000] = {0};
        vector<int> suc[1000];
        scanf("%d %d", &N, &K);
        for(int i=0; i<N; i++)
            scanf("%d", time+i);
        for(int i=0; i<K; i++){
            int X, Y;
            scanf("%d %d", &X, &Y);
            suc[X-1].push_back(Y-1);
            pre[Y-1]++;
        }
        scanf("%d", &W);
        W--;
 
 		// 위상정렬을 하며 각 건물의 최소 건설시작시간 계산
        int result[1000] = {0};
        queue<int> Q;
        for(int i=0; i<N; i++)
            if(!pre[i]) Q.push(i);
        while(pre[W] > 0){
            int u = Q.front();
            Q.pop();
            for(int next: suc[u]){
                result[next] = max(result[next], result[u]+time[u]);
                if(--pre[next] == 0) Q.push(next);
            }
        }
        printf("%d\n", result[W]+time[W]);
    }
}