#include <cstdio>
using namespace std;

int main(){
    char N[20] = {0,};
    scanf("%s", N);
    for(int i = 2; N[i]; ++i){
        if(N[i-1]-N[i-2] != N[i]-N[i-1]){
            puts("흥칫뿡!! <(￣ ﹌ ￣)>");
            return 0;
        }
    }
    puts("◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!");
}