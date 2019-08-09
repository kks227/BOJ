#include <cstdio>
using namespace std;

int main(){
    int N;
    char S[14][8] = {"baby", "sukhwan", "", "", "very", "cute", "", "", "in", "bed", "", "", "baby", "sukhwan"};
    scanf("%d", &N);
    int k = --N % 14;
    if(k%4 < 2) puts(S[k]);
    else{
        int l = !(k%4-2) + 1 + N/14;
        if(l >= 5) printf("tu+ru*%d\n", l);
        else{
            printf("tu");
            for(int i = 0; i < l; ++i)
                printf("ru");
            puts("");
        }
    }
}