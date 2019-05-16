#include <cstdio>
using namespace std;

int main(){
    int N, cnt[2] = {0,};
    scanf("%d\n", &N);
    for(int i = 0; i < N; ++i)
        ++cnt[getchar() == 'e'];
    if(cnt[0] == cnt[1]) puts("yee");
    else putchar(cnt[0] > cnt[1] ? '2' : 'e');
}