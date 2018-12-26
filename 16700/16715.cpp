#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int N, res1 = -1, res2 = -1;
    scanf("%d", &N);
    for(int i = 2; i <= N; ++i){
        int k = N, sum = 0;
        while(k > 0){
            sum += k%i;
            k /= i;
        }
        if(res1 < sum){
            res1 = sum;
            res2 = i;
        }
    }
    printf("%d %d\n", res1, res2);
}