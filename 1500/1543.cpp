#include <cstdio>
#include <cstring>
using namespace std;
 
int main(){
    char doc[2501], word[51];
    gets(doc);
    gets(word);
    int H = strlen(doc);
    int N = strlen(word);
    int result = 0;
    for(int i=0; i<=H-N;){
        bool find = true;
        for(int j=0; j<N; j++)
            if(doc[i+j] != word[j]){
                find = false;
                break;
            }
        if(find){
            result++;
            i += N;
        }
        else i++;
    }
    printf("%d\n", result);
}