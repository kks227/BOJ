#include <cstdio>
using namespace std;

int main(){
    int N;
    while(scanf("%d", &N) > 0){
        int p10 = 1 % N;
        for(int i = 1; ; ++i){
            if(p10 == 0){
                printf("%d\n", i);
                break;
            }
            p10 = (p10*10 + 1) % N;
        }
    }
}