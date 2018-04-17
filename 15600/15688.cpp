#include <cstdio>
using namespace std;
const int OFF = 1000000;

int main(){
    int N, cnt[2*OFF+1] = {0,};
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        int val;
        scanf("%d", &val);
        cnt[val+OFF]++;
    }
    for(int i=0; i<=2*OFF; i++)
        for(int j=0; j<cnt[i]; j++)
            printf("%d\n", i-OFF);
}