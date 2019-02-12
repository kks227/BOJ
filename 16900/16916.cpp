#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int MAX = 1000000;

int main(){
    char S[MAX+1], P[MAX+1];
    int M, N;
    scanf("%s %s", S, P);
    N = strlen(S);
    M = strlen(P);

    int p[MAX] = {0};
    for(int i = 1, j = 0; i < M; ++i){
        while(j > 0 && P[i] != P[j]) j = p[j-1];
        if(P[i] == P[j]) p[i] = ++j;
    }
    for(int i = 0, j = 0; i < N; ++i){
        while(j > 0 && S[i] != P[j]) j = p[j-1];
        if(S[i] == P[j]){
            if(j == M-1){
                puts("1");
                return 0;
            }
            ++j;
        }
    }
    puts("0");
}