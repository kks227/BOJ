#include <cstdio>
using namespace std;
const int N = 100000;

int main(){
    char A[N], B[N];
    scanf("%s %s", A, B);
    for(int i = 0; i < N; ++i)
        printf("%d", A[i]-'0' && B[i]-'0');
    puts("");
    for(int i = 0; i < N; ++i)
        printf("%d", A[i]-'0' || B[i]-'0');
    puts("");
    for(int i = 0; i < N; ++i)
        printf("%d", A[i]-'0' ^ B[i]-'0');
    puts("");
    for(int i = 0; i < N; ++i)
        printf("%d", !(A[i]-'0'));
    puts("");
    for(int i = 0; i < N; ++i)
        printf("%d", !(B[i]-'0'));
    puts("");
}