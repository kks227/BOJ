#include <cstdio>
using namespace std;

int main(){
    unsigned int N, k;
    scanf("%u %u", &N, &k);
    if(N >= 6) puts("Love is open door");
    else{
        for(int i = 1; i < N; ++i)
            printf("%u\n", (k+i)%2);
    }
}