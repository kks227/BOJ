#include <cstdio>
using namespace std;
const int MAX = 5000;

int main(){
    char S[MAX+2] = {0,};
    scanf("%s", S);
    for(int i = 0; S[i]; ++i){
        bool flag = false;
        if(S[i] == 'p'){
            if(S[i+1] != 'i') flag = true;
            else ++i;
        }
        else if(S[i] == 'k'){
            if(S[i+1] != 'a') flag = true;
            else ++i;
        }
        else if(S[i] == 'c'){
            if(S[i+1] != 'h' || S[i+2] != 'u') flag = true;
            else i += 2;
        }
        else flag = true;
        if(flag){
            puts("NO");
            return 0;
        }
    }
    puts("YES");
}