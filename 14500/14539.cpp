#include <cstdio>
using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t){
        int r, c, w, h;
        scanf("%d %d %d %d", &r, &c, &w, &h);
        printf("Case #%d:\n+", t);
        for(int i = 0; i < c; ++i){
            for(int j = 0; j < w; ++j)
                putchar('-');
            putchar('+');
        }
        puts("");
        for(int i = 0; i < r; ++i){
            for(int j = 0; j < h; ++j){
                putchar('|');
                for(int k = 0; k < c; ++k){
                    for(int l = 0; l < w; ++l)
                        putchar('*');
                    putchar('|');
                }
                puts("");
            }
            putchar('+');
            for(int j = 0; j < c; ++j){
                for(int k = 0; k < w; ++k)
                    putchar('-');
                putchar('+');
            }
            puts("");
        }
    }
}