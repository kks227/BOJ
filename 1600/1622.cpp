#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 1001;

int main(){
    char A[MAX], B[MAX];
    while(gets(A) > 0 && gets(B) > 0){
        int cnt[2][26] = {0,};
        for(int i = 0; A[i]; ++i)
            ++cnt[0][A[i]-'a'];
        for(int i = 0; B[i]; ++i)
            ++cnt[1][B[i]-'a'];
        for(int i = 0; i < 26; ++i)
            for(int j = 0; j < min(cnt[0][i], cnt[1][i]); ++j)
                putchar(i+'a');
        puts("");
    }
}