#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 250000;

int main(){
    char S[MAX+1];
    long long k;
    scanf("%s %d", S, &k);
    int L = strlen(S);
    for(int i = 0; i < L/2; ++i){
        if(S[i] != S[L-i-1]){
            puts("NO");
            return 0;
        }
    }
    puts("YES");
}