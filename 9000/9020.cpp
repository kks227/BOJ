#include <cstdio>
#include <cstring>
using namespace std;
 
#define MAX 10000
 
int main(){
 
    bool prime[MAX+1];
    memset(prime, 1, MAX+1);
    for(int i=2; i<=MAX; i++){
        if(!prime[i]) continue;
        for(int j=i*2; j<=MAX; j+=i)
            prime[j] = false;
    }
 
    int T, n;
    scanf("%d", &T);
    for(int i=0; i<T; i++){
        scanf("%d", &n);
        for(int j=n/2; j>1; j--){
            if(prime[j] && prime[n-j]){
				printf("%d %d\n", j, n-j);
                break;
            }
        }
    }
 
    return 0;
}