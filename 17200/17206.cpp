#include <cstdio>
using namespace std;
const int MAX = 80001;

int main(){
    int result[MAX] = {0,}, T;
    for(int i = 1; i < MAX; ++i)
        result[i] = result[i-1] + (i%3 == 0 || i%7 == 0 ? i : 0);
    scanf("%d", &T);
    for(int t = 0; t < T; ++t){
        int N;
        scanf("%d", &N);
        printf("%d\n", result[N]);
    }
}