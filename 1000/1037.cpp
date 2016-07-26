#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
 
int main(){
 
    int N, M;
    vector<int>input;
    priority_queue<int> sort;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &M);
        sort.push(M);
    }
    for(int i=0; i<N; i++){
        input.push_back(sort.top());
        sort.pop();
    }
 
    if(N%2==0) printf("%d\n", input[N/2-1]*input[N/2]);
    else printf("%d\n", input[N/2]*input[N/2]);
 
    return 0;
}