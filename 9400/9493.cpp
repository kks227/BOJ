#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    while(1){
        int M, A, B;
        scanf("%d %d %d", &M, &A, &B);
        if(M == 0) break;

        int s = round(3600.0*M*(B-A)/A/B);
        int h = s / 3600, m = s % 3600 / 60;
        s %= 60;
        printf("%d:%02d:%02d\n", h, m, s);
    }
}