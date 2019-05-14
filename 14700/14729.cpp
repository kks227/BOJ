#include <cstdio>
#include <queue>
using namespace std;
const int K = 7;

int main(){
    int N;
    priority_queue<double> PQ;
    scanf("%d", &N);
    double val, result[K];
    for(int i = 0; i < K; ++i){
        scanf("%lf", &val);
        PQ.push(val);
    }
    for(int i = K; i < N; ++i){
        scanf("%lf", &val);
        PQ.push(val);
        PQ.pop();
    }
    for(int i = 0; i < K; ++i){
        result[6-i] = PQ.top();
        PQ.pop();
    }
    for(int i = 0; i < K; ++i)
        printf("%.3lf\n", result[i]);
}