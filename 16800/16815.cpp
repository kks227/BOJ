#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 101;

int main(){
    char S[MAX];
    scanf("%s", S);
    int pos = 0, result = 0;
    while(S[pos++] != '*');
    for(int i = 0; S[pos]; ++pos){
        if(S[pos] == '(') --i;
        else result = max(++i, result);
    }
    printf("%d\n", result);
}