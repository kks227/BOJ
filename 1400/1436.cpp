#include <cstdio>
using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    for(int i = 666; ; ++i){
        bool flag = false;
        int j = i;
        do{
            if(j%1000 == 666){
                flag = true;
                break;
            }
            j /= 10;
        }while(j >= 666);
        if(flag && --N == 0){
            printf("%d\n", i);
            return 0;
        }
    }
}