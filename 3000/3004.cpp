#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    printf("%d\n", (N/2+1) * (N/2+N%2+1));
}