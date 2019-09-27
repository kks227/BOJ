#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int main(){
    int N, result = INF, ri, rj, rk;
    scanf("%d", &N);
    for(int i = 1; i*i*i <= N; ++i){
        if(N%i) continue;
        for(int j = i; i*j*j <= N; ++j){
            if(N/i%j) continue;
            int k = N/i/j, temp = 2*(i*j+j*k+k*i);
            if(temp < result){
                result = temp;
                ri = i;
                rj = j;
                rk = k;
            }
        }
    }
    printf("%d %d %d\n", ri, rj, rk);
}