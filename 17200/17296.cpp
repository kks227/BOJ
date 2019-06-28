#include <cstdio>
using namespace std;

int main(){
    int N, result = 0;
    bool pressA = false;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        double x;
        scanf("%lf", &x);
        if(!pressA && x > 0){
            result += (int)(x + 0.5);
            pressA = true;
        }
        else result += (int)x;
    }
    printf("%d\n", result);
}