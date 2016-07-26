#include <cstdio>
using namespace std;
 
int size[16] = {1};
 
int Z(int n, int r, int c){
    if(n==0) return 1;
    if(r < size[n-1]){
        if(c < size[n-1]) return Z(n-1, r, c);
        else return size[n-1]*size[n-1] + Z(n-1, r, c-size[n-1]);
    }
    else{
        if(c < size[n-1]) return size[n-1]*size[n-1]*2 + Z(n-1, r-size[n-1], c);
        else return size[n-1]*size[n-1]*3 + Z(n-1, r-size[n-1], c-size[n-1]);
    }
}
 
int main(){
 
    int N, R, C;
    for(int i=1; i<16; i++)
        size[i] = size[i-1]*2;
    while(scanf("%d %d %d", &N, &R, &C) > 0)
        printf("%d\n", Z(N, R, C)-1);
 
    return 0;
}