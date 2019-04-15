#include <cstdio>
#include <vector>
#include <queue>
#include <set>
using namespace std;
const int N = 3;
typedef vector<int> Node;

int main(){
    Node s(3);
    for(int i = 0; i < N; ++i){
        int k;
        scanf("%d", &k);
        if(k > 0) getchar();
        for(int j = 0; j < k; ++j){
            char c = getchar();
            s[i] = s[i]*4 + (c - 'A' + 1);
        }
    }
    queue<Node> Q;
    Q.push(s);
    set<Node> visited;
    visited.insert(s);
    for(int result = 0; ; ++result){
        int qSize = Q.size();
        for(int i = 0; i < qSize; ++i){
            Node curr(Q.front());
            Q.pop();
            bool flag = true;
            for(int j = 0; j < N && flag; ++j){
                int k = curr[j];
                while(k > 0){
                    if(k%4 != j+1){
                        flag = false;
                        break;
                    }
                    k /= 4;
                }
            }
            if(flag){
                printf("%d\n", result);
                return 0;
            }

            for(int j = 0; j < N; ++j){
                if(curr[j] == 0) continue;
                for(int k = 0; k < N; ++k){
                    if(j == k) continue;
                    Node next(curr);
                    next[k] = next[k]*4 + next[j]%4;
                    next[j] /= 4;
                    if(visited.find(next) == visited.end()){
                        visited.insert(next);
                        Q.push(next);
                    }
                }
            }
        }
    }
}