#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int main(){
    int M;
    char S[3][14] = {"Gimossi", "Messi", "Messi Gimossi"};
    scanf("%d", &M);
    --M;

    vector<int> dp(3);
    dp[0] = 7;
    dp[1] = 5;
    dp[2] = 13;
    for(int i = 3; ; ++i){
        int temp = dp[i-2] + dp[i-1] + 1;
        dp.push_back(temp);
        if(temp > M) break;
    }
    for(int i = dp.size()-1; i > 2; --i){
        if(M == dp[i-1]){
            puts("Messi Messi Gimossi");
            return 0;
        }
        if(M > dp[i-1]){
            M -= dp[i-1] + 1;
            --i;
        }
    }
    if(S[2][M] == ' ') puts("Messi Messi Gimossi");
    else putchar(S[2][M]);
}