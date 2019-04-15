#include <cstdio>
#include <stack>
#include <queue>
#include <utility>
#include <unordered_map>
#include <functional>
using namespace std;
const long long INF = 1e18;
typedef pair<int, char> PrevNode;
typedef function<long long(int)> Func;

int main(){
    int s, t;
    scanf("%d %d", &s, &t);
    if(s == t){
        puts("0");
        return 0;
    }

    Func f[4] = {
        [](int k){ return 1LL*k*k; },
        [](int k){ return k*2; },
        [](int k){ return 0; },
        [](int k){ return (k > 0 ? 1 : INF); }
    };
    char c[4] = {'*', '+', '-', '/'};
    unordered_map<int, PrevNode> visited;
    visited[s] = PrevNode(-1, '?');
    queue<int> Q;
    Q.push(s);

    for(int result = 0; !Q.empty(); ++result){
        int qSize = Q.size();
        for(int i = 0; i < qSize; ++i){
            int curr = Q.front(); Q.pop();
            if(curr == t){
                stack<char> result;
                while(t != s){
                    result.push(visited[t].second);
                    t = visited[t].first;
                }
                while(!result.empty()){
                    putchar(result.top());
                    result.pop();
                }
                return 0;
            }

            for(int j = 0; j < 4; ++j){
                long long next = f[j](curr);
                if(next > t) continue;
                if(visited.find(next) == visited.end()){
                    visited[next] = PrevNode(curr, c[j]);
                    Q.push(next);
                }
            }
        }
    }
    puts("-1");
}