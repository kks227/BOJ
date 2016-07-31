#include <cstdio>
using namespace std;
 
// 2^N을 구해두는 배열. 이건 그냥 << 연산을 사용해도 괜찮다.
int size[16] = {1};
 
// 크기가 2^n이고 찾을 좌표가 왼쪽 위로부터 상대 좌표 (r, c)
int Z(int n, int r, int c){
    // base case: 찾음
    if(n==0) return 1;

    // 상단에 위치
    if(r < size[n-1]){
        // 왼쪽에 위치
        if(c < size[n-1]) return Z(n-1, r, c);
        // 오른쪽에 위치
        else return size[n-1]*size[n-1] + Z(n-1, r, c-size[n-1]);
    }
    // 하단에 위치
    else{
        // 왼쪽에 위치
        if(c < size[n-1]) return size[n-1]*size[n-1]*2 + Z(n-1, r-size[n-1], c);
        // 오른쪽에 위치
        else return size[n-1]*size[n-1]*3 + Z(n-1, r-size[n-1], c-size[n-1]);
    }
}
 
int main(){
    int N, R, C;
    for(int i=1; i<16; i++)
        size[i] = size[i-1]*2;
    while(scanf("%d %d %d", &N, &R, &C) > 0)
        printf("%d\n", Z(N, R, C)-1);
}