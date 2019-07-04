#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 1000000;

int main(){
    int N;
    double result = -1e18, M, minF;
    scanf("%lf %d %lf", &M, &N, &minF);
    for(int i = 1; i < N; ++i){
        double f;
        scanf("%lf", &f);
        result = max(M/minF*f, result);
        minF = min(f, minF);
    }
    printf("%.2lf\n", result-M);
}