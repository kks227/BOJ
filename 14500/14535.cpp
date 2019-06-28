#include <cstdio>
#include <cstring>
#include <numeric>
#include <algorithm>
using namespace std;

int main(){
    char Mon[12][4] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    for(int t = 1; ; ++t){
        int N;
        scanf("%d", &N);
        if(N == 0) break;
        
        int cnt[12] = {0,};
        for(int i = 0; i < N; ++i){
            int d, m, y;
            scanf("%d %d %d", &d, &m, &y);
            ++cnt[m-1];
        }
        printf("Case #%d:\n", t);
        for(int i = 0; i < 12; ++i){
            printf("%s:", Mon[i]);
            for(int j = 0; j < cnt[i]; ++j)
                putchar('*');
            puts("");
        }
    }
}