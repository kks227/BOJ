#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 10;

int main(){
    int sr, sc, result = N*2-2;
    bool br[N] = {false,}, bc[N] = {false,};
    scanf("%d %d", &sr, &sc);
    --sr; --sc;
    for(int i = 0; i < N; ++i){
        getchar();
        for(int j = 0; j < N; ++j)
            if(getchar() == 'o') br[i] = bc[j] = true;
    }
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            if(!br[i] && !bc[j]) result = min(abs(i-sr)+abs(j-sc), result);
    printf("%d\n", result);
}