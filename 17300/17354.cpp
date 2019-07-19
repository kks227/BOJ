#include <cstdio>
using namespace std;

int main(){
    int w, h, W, H, x, y, dx, dy;
    scanf("%d %d %d %d %d %d %d %d", &w, &h, &W, &H, &x, &y, &dx, &dy);
    if(dx < 0) x = W-w-x;
    if(dy < 0) y = H-h-y;
    W -= w;
    H -= h;
    for(int k = 0; k <= H; ++k){
        long long t = W-x + 1LL*k*W;
        if((y+t)%H == 0){
            printf("%lld\n", t);
            return 0;
        }
    }
    puts("-1");
}