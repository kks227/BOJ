#include <cstdio>
using namespace std;

int main(){
    int N, result = 1;
    bool visited[100] = {false,};
    scanf("%d", &N);
    while(N > 0){
        int temp = N%1000/10;
        if(visited[temp]) break;
        visited[temp] = true;
        N = temp*temp;
        ++result;
    }
    printf("%d\n", result);
}