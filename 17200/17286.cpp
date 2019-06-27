#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int main(){
    int x[4], y[4], p[4] = {0, 1, 2, 3}, result = INF;
    for(int i = 0; i < 4; ++i)
        scanf("%d %d", x+i, y+i);
    do{
        double sum = 0;
        for(int i = 1; i < 4; ++i)
            sum += sqrt(pow(x[p[i]]-x[p[i-1]], 2.0) + pow(y[p[i]]-y[p[i-1]], 2.0));
        result = min((int)(sum + 1e-6), result);
    }while(next_permutation(p+1, p+4));
    printf("%d\n", result);
}