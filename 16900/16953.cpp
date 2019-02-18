#include <cstdio>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int IMPOSSIBLE = 1e9;

int A, B;
unordered_map<int, int> dp;

int f(int n){
    if(dp.find(n) != dp.end()) return dp[n];
    if(n == A) return dp[n] = 1;
    if(n < A) return dp[n] = IMPOSSIBLE;

    int ret = IMPOSSIBLE;
    if(n%2 == 0) ret = min(f(n/2)+1, ret);
    if(n%10 == 1) ret = min(f(n/10)+1, ret);
    return dp[n] = ret;
}

int main(){
    scanf("%d %d", &A, &B);
    int result = f(B);
    if(result == IMPOSSIBLE) result = -1;
    printf("%d\n", result);
}