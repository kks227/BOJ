#include <cstdio>
#include <cstring>
#include <numeric>
#include <algorithm>
using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t){
        char S[21];
        scanf("%s", S);
        printf("Case # %d:\n", t);
        int p[20], L = strlen(S);
        iota(p, p+L, 0);
        do{
            for(int i = 0; i < L; ++i)
                putchar(S[p[i]]);
            puts("");
        }while(next_permutation(p, p+L));
    }
}