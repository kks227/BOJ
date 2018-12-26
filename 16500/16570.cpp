#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int MAX = 1000000;

int main(){
    int N, A[MAX], fail[MAX] = {0}, res1 = -1, res2 = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%d", A+(N-i-1));
    for(int i = 1, j = 0; i < N; ++i){
        while(j > 0 && A[i] != A[j]) j = fail[j-1];
        if(A[i] == A[j]) fail[i] = ++j;
    }
    for(int i = 0; i < N; ++i){
        if(fail[i] > 0){
            if(fail[i] > res1){
                res1 = fail[i];
                res2 = 1;
            }
            else if(fail[i] == res1) ++res2;
        }
    }
    if(res1 < 0) puts("-1");
    else printf("%d %d\n", res1, res2);
}