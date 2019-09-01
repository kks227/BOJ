#include <cstdio>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 200;

int main(){
    while(1){
        int N, prev[MAX];
        char pc[MAX];
        scanf("%d", &N);
        if(N == 0) break;

        bool visited[MAX] = {false,};
        queue<int> Q;
        Q.push(1);
        visited[1] = true;
        for(int i = 0; i < 100; ++i){
            int qSize = Q.size();
            for(int j = 0; j < qSize; ++j){
                int curr = Q.front(); Q.pop();
                for(int k = 0; k < 2; ++k){
                    int next = (curr*10 + k) % N;
                    if(!visited[next]){
                        prev[next] = curr;
                        pc[next] = k + '0';
                        visited[next] = true;
                        Q.push(next);
                    }
                }
            }
        }

        int curr = 0;
        stack<char> result;
        do{
            result.push(pc[curr]);
            curr = prev[curr];
        }while(curr != 1);
        result.push('1');
        while(!result.empty()){
            putchar(result.top());
            result.pop();
        }
        puts("");
    }
}