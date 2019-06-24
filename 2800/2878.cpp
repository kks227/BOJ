#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 100000;

int main(){
    int N, M, A[MAX], lo = 0, hi = 0;
    scanf("%d %d", &M, &N);
    for(int i = 0; i < N; ++i){
        scanf("%d", A+i);
        hi = max(A[i], hi);
    }
    while(lo+1 < hi){
        int mid = (lo+hi)/2;
        long long sum = 0;
        for(int i = 0; i < N; ++i)
            if(A[i] > mid) sum += A[i] - mid;
        (sum > M ? lo : hi) = mid;
    }

    priority_queue<int> PQ;
    for(int i = 0; i < N; ++i){
        int temp = (A[i] <= hi ? 0 : A[i] - hi);
        PQ.push(A[i] - temp);
        M -= temp;
    }
    for(int i = 0; i < M; ++i){
        int temp = PQ.top();
        PQ.pop();
        PQ.push(temp - 1);
    }
    unsigned long long result = 0;
    while(!PQ.empty()){
        unsigned long long temp = PQ.top();
        PQ.pop();
        result += temp * temp;
    }
    printf("%llu\n", result);
}