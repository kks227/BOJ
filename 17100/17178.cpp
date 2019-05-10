#include <cstdio>
#include <stack>
#include <tuple>
#include <algorithm>
using namespace std;
const int MAX = 500;
typedef tuple<char, int, int> Node;

int main(){
    int N, k[MAX], cnt = 0;
    scanf("%d", &N);
    N *= 5;
    Node node[MAX];
    for(int i = 0; i < N; ++i){
        char c;
        int j;
        scanf(" %c-%d", &c, &j);
        node[i] = Node(c, j, i);
    }
    sort(node, node+N);
    for(int i = 0; i < N; ++i)
        k[get<2>(node[i])] = i;

    stack<int> S;
    for(int i = 0; i < N; ++i){
        S.push(k[i]);
        while(!S.empty() && S.top() == cnt){
            S.pop();
            ++cnt;
        }
    }
    puts(S.empty() ? "GOOD" : "BAD");
}