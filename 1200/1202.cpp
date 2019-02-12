#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 300000;
typedef pair<int, int> P;

int main(){
    int N, K, C[MAX];
    P p[MAX];
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; ++i)
        scanf("%d %d", &p[i].first, &p[i].second);
    sort(p, p+N);
    for(int i = 0; i < K; ++i)
        scanf("%d", C+i);
    sort(C, C+K);

    long long result = 0;
    priority_queue<int> PQ;
    for(int i = 0, j = 0; i < K; ++i){
        for(; j < N && p[j].first <= C[i]; ++j)
            PQ.push(p[j].second);
        if(!PQ.empty()){
            result += PQ.top();
            PQ.pop();
        }
    }
    printf("%lld\n", result);
}