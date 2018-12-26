#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 1000001;

int main(){
    int N, go[3] = {0,};
    scanf("%d %d %d", &N, go+1, go+2);
    bool visited[MAX] = {false,};
    queue<int> Q;
    visited[N] = true;
    Q.push(N);
    for(int result = 0; ; ++result){
        int qSize = Q.size();
        for(int i = 0; i < qSize; ++i){
            int curr = Q.front(); Q.pop();
            if(curr == 0){
                printf("%d\n", result);
                return 0;
            }

            for(int j = 0; j < 3; ++j){
                int next = curr - go[j] - 1;
                if(next >= 0 && !visited[next]){
                    visited[next] = true;
                    Q.push(next);
                }
            }
        }
    }
}