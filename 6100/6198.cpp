#include <cstdio>
#include <stack>
using namespace std;
const int MAX = 80000;

int main(){
    int N, H[MAX];
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%d", H+i);
    long long result = 0;
    stack<int> S;
    for(int i = 0; i < N; ++i){
        while(!S.empty() && H[S.top()] <= H[i]){
            result += i - S.top() - 1;
            S.pop();
        }
        S.push(i);
    }
    while(!S.empty()){
        result += N - S.top() - 1;
        S.pop();
    }
    printf("%lld\n", result);
}