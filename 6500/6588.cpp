#include <cstdio>
using namespace std;
 
#define MAX 1000
 
int main(){
   
    bool np[MAX*MAX/2] = {0};
    int i, j;
    for(i=3; i<=MAX; i+=2){
        if(np[i/2]) continue;
        for(j=i*i; j<=MAX*MAX; j+=i*2)
            np[j/2] = true;
    }
   
    int n;
    while(1){
        scanf("%d", &n);
        if(n == 0) break;
        for(i=3; ; i+=2){
            if(!np[i/2] && !np[(n-i)/2]){
                printf("%d = %d + %d\n", n, i, n-i);
                break;
            }
        }
    }
   
    return 0;
}