#include <cstdio>
#include <vector>
#include <stack>
#include <utility>
using namespace std;
typedef pair<bool, int> Node;

int main(){
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t){
        vector<Node> P;
        vector<char> ops;
        stack<char> S1;
        int val;
        scanf("%d", &val);
        P.push_back(Node(true, val));
        while(1){
            if(getchar() != ' ') break;
            char op = getchar();
            if(op == '+' || op == '-'){
                while(!S1.empty()){
                    P.push_back(Node(false, S1.top()));
                    S1.pop();
                }
            }
            else{
                while(!S1.empty() && (S1.top() == '*' || S1.top() == '/')){
                    P.push_back(Node(false, S1.top()));
                    S1.pop();
                }
            }
            S1.push(op);
            scanf("%d", &val);
            P.push_back(Node(true, val));
            ops.push_back(op);
        }
        while(!S1.empty()){
            P.push_back(Node(false, S1.top()));
            S1.pop();
        }

        stack<int> S2;
        printf("Case #%d:", t);
        for(char c: ops)
            if(c == '*' || c == '/') printf(" %c", c);
        for(char c: ops)
            if(c == '+' || c == '-') printf(" %c", c);
        for(auto &p: P){
            if(p.first) S2.push(p.second);
            else{
                int b = S2.top(); S2.pop();
                int a = S2.top(); S2.pop();
                int c;
                if(p.second == '+') c = a + b;
                else if(p.second == '-') c = a - b;
                else if(p.second == '*') c = a * b;
                else c = a / b;
                S2.push(c);
            }
        }
        printf(" %d\n", S2.top());
    }
}