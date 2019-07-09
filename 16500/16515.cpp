#include <cstdio>
using namespace std;

int main(){
    int N;
    double temp = 1, result = 1;
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i){
        temp /= i;
        result += temp;
    }
    printf("%.15lf\n", result);
}