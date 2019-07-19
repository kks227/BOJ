#include <cstdio>
using namespace std;
const int N = 9;

int main(){
    int A[N][2];
    for(int i = 0; i < N; ++i){
        scanf("%d %d", &A[i][0], &A[i][1]);
        --A[i][1];
    }
    int result = -1;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            bool flag = true;
            for(int k = 0; k < N; ++k){
                if(k == i){
                    if(A[k][0] && A[k][1] == j) flag = false;
                    if(!A[k][0] && A[k][1] != j) flag = false;
                }
                else{
                    if(A[k][0] && A[k][1] != j) flag = false;
                    if(!A[k][0] && A[k][1] == j) flag = false;
                }
            }
            if(flag){
                if(result != -1){
                    puts("-1");
                    return 0;
                }
                result = j+1;
            }
        }
    }
    printf("%d\n", result);
}