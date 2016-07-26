// [Geometry]

#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
 
int main(){
    int T, x1, x2, y1, y2, r1, r2;
    double dist;
    scanf("%d", &T);
    for(int i=0; i<T; i++){
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        // 두 원의 중심이 일치할 경우
        if(x1==x2 && y1==y2){
            if(r1 == r2) puts("-1"); // 두 원이 일치함
            else puts("0");
            continue;
        }
 
        dist = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
        if(r1 < r2) swap(r1, r2);
        if(dist == r1) puts("2");
        else if(dist > r1){
            if(dist < r1+r2) puts("2");
            else if(dist == r1+r2) puts("1");
            else puts("0");
        }
        else{
            if(dist > r1-r2) puts("2");
            else if(dist == r1-r2) puts("1");
            else puts("0");
        }
    }
}