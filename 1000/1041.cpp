#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 1001;

int main(){
    int N, val[6], sum = 0, minVal = INF, maxVal = 0, A[8][3] = {
        0, 1, 2, 0, 1, 3, 0, 2, 4, 0, 3, 4,
        1, 2, 5, 1, 3, 5, 2, 4, 5, 3, 4, 5
    };
    scanf("%d", &N);
    for(int i = 0; i < 6; ++i){
        scanf("%d", val+i);
        sum += val[i];
        minVal = min(val[i], minVal);
        maxVal = max(val[i], maxVal);
    }

    if(N == 1) printf("%d\n", sum - maxVal);
    else{
        int temp = INF;
        long long result = 0;
        for(int i = 0; i < 8; ++i){
            int k = 0;
            for(int j = 0; j < 3; ++j)
                k += val[A[i][j]];
            temp = min(k, temp);
        }
        result += 4 * temp;
        temp = INF;
        for(int i = 0; i < 6; ++i)
            for(int j = 0; j < 6; ++j)
                if(i != j && j != 5-i) temp = min(val[i]+val[j], temp);
        result += ( (N-1)*4 + (N-2)*4 ) * temp;
        result += ( 1LL*(N-2)*(N-2) + 1LL*(N-1)*(N-2)*4 ) * minVal;
        printf("%lld\n", result);
    }
}