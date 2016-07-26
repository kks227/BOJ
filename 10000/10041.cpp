#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
    int W, H, N;
    scanf("%d %d %d", &W, &H, &N);
    int prevX, prevY, result = 0;
    scanf("%d %d", &prevX, &prevY);
    for(int i=1; i<N; i++){
        int X, Y;
        scanf("%d %d", &X, &Y);
        if(prevX<X && prevY<Y || X<prevX && Y<prevY) result += max(abs(X-prevX), abs(Y-prevY));
        else result += abs(X-prevX) + abs(Y-prevY);
        prevX = X;
        prevY = Y;
    }
    printf("%d\n", result);
}