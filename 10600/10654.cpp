#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;
const int MAX = 100000;
typedef pair<int, int> P;

int main(){
    int N, T;
    P p[MAX];
    scanf("%d %d", &N, &T);
    for(int i = 0; i < N; ++i)
        scanf("%d %d", &p[i].first, &p[i].second);
    sort(p, p+N);
    int result = N;
    stack<int> S;
    for(int i = 0; i < N; ++i){
        while(!S.empty()){
            int x1 = p[S.top()].first, v1 = p[S.top()].second;
            int x2 = p[i].first, v2 = p[i].second;
            if(x2-x1 <= 1LL*T*(v1-v2)){
                --result;
                S.pop();
            }
            else break;
        }
        S.push(i);
    }
    printf("%d\n", result);
}