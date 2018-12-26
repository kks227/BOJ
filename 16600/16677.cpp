#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
    char W[101], S[100][101];
    int N, L[100], g[100];
    scanf("%s %d", W, &N);
    for(int i = 0; i < N; ++i){
        scanf("%s %d", S[i], g+i);
        L[i] = strlen(S[i]);
    }
    int p = 0, q = 1, index = -1;
    for(int i = 0; i < N; ++i){
        int j = 0;
        for(int k = 0; W[j] && S[i][k]; ++k)
            if(W[j] == S[i][k]) ++j;
        if(!W[j]){
            int p0 = g[i], q0 = L[i]-j;
            if(p*q0 < q*p0){
                p = p0;
                q = q0;
                index = i;
            }
        }
    }
    if(index < 0) puts("No Jam");
    else puts(S[index]);
}