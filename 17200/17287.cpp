#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    char S[101];
    scanf("%s", S);
    int cnt[4] = {0,}, result = 0;
    for(int i = 0; S[i]; ++i){
        char c = S[i];
        if(c == '(') ++cnt[1];
        else if(c == ')') --cnt[1];
        else if(c == '{') ++cnt[2];
        else if(c == '}') --cnt[2];
        else if(c == '[') ++cnt[3];
        else if(c == ']') --cnt[3];
        else result = max(cnt[1]+2*cnt[2]+3*cnt[3], result);
    }
    printf("%d\n", result);
}