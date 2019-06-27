#include <cstdio>
using namespace std;

int main(){
    char S[101];
    scanf("%s", S);
    int result = 0;
    for(int i = 0, j; S[i]; ++i){
        for(j = 1; S[i+j]; ++j)
            if(S[i+j] != S[i]+j) break;
        if(j == 3) ++result;
        i += j-1;
    }
    printf("%d\n", result);
}