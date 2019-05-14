#include <cstdio>
#include <stack>
using namespace std;
const int MAX = 1000;

int main(){
    int N, H[MAX] = {0,}, result = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        int x, h;
        scanf("%d %d", &x, &h);
        H[x-1] = h;
    }
    stack<int> S1, S2;
    for(int i = 0; i < MAX; ++i){
        if(H[i] == 0) continue;
        if(S1.empty()) S1.push(i);
        else{
            int y = H[S1.top()];
            if(H[i] > y){
                result += (i-S1.top())*y;
                S1.push(i);
            }
        }
    }
    for(int i = MAX-1; i >= 0; --i){
        if(H[i] == 0) continue;
        if(S2.empty()) S2.push(i);
        else{
            int y = H[S2.top()];
            if(H[i] > y){
                result += (S2.top()-i)*y;
                S2.push(i);
            }
        }
    }
    result += (S2.top()-S1.top()+1)*H[S1.top()];
    printf("%d\n", result);
}