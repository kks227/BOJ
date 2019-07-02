#include <cstdio>
using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    for(int t = 0; t < T; ++t){
        char S[17];
        scanf("%s", S);
        int temp = 0;
        for(int i = 0; i < 16; ++i){
            int k = (i%2 ? S[i]-'0' : (S[i]-'0')*2);
            if(k > 9) k = k%10 + 1;
            temp = (temp + k) % 10;
        }
        puts(temp ? "F" : "T");
    }
}