#include <cstdio>
#include <cmath>
#include <numeric>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int main(){
    int A[8], p[8];
    iota(p, p+8, 0);
    for(int i = 0; i < 8; ++i)
        scanf("%d", A+i);

    int result = INF;
    do{
        int temp = 0;
        for(int k = 0; k < 2; ++k)
            temp = max(abs(A[p[k*4]]+A[p[k*4+1]]-A[p[k*4+2]]-A[p[k*4+3]]), temp);
        result = min(temp, result);
    }while(next_permutation(p, p+8));
    if(result == 0) puts("1.0");
    else if(result == 20) puts("0.0");
    else printf((result%2 == 0 ? "%.1f\n" : "%.2lf\n"), 1 - result/20.0);
}