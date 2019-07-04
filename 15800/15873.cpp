#include <cstdio>
using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    printf("%d\n", N%10 ? N/10 + N%10 : N/100 + N%100);
}