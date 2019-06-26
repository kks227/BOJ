#include <cstdio>
using namespace std;

int main(){
    char S[101];
    scanf("%s", S);
    int key = S[0] ^ 'C';
    for(int i = 0; S[i]; ++i)
        S[i] ^= key;
    puts(S);
}