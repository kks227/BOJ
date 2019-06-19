#include <cstdio>
using namespace std;
const int MAX = 200001;

int main(){
    int pSum[26][MAX] = {0,}, Q;
    for(int i = 0; ; ++i){
        char c = getchar();
        if(c == '\n') break;
        for(int j = 0; j < 26; ++j)
            pSum[j][i+1] = pSum[j][i] + (c == 'a'+j ? 1 : 0);
    }
    scanf("%d", &Q);
    for(int q = 0; q < Q; ++q){
        char c;
        int s, e;
        scanf(" %c %d %d", &c, &s, &e);
        printf("%d\n", pSum[c-'a'][e+1] - pSum[c-'a'][s]);
    }
}