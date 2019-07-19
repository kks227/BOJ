#include <cstdio>
#include <cstring>
using namespace std;

int main(){
    int N;
    bool result = false;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        char S[100];
        scanf("%s", S);
        if(strcmp(S, "anj") == 0) result = true;
    }
    puts(result ? "뭐야;" : "뭐야?");
}