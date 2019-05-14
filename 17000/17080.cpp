#include <cstdio>
using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    printf("%d\n", N%4 == 3 ? 2 : 1);
}