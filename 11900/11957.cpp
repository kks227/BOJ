#include <cstdio>
#include <stack>
using namespace std;

int main(){
    int N;
    double R[9];
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%lf", R+i);
    char E[100001];
    scanf("%s", E);

    stack<double> S;
    stack<int> cnt;
    stack<int> type;
    cnt.push(0);
    type.push(-1);
    for(int i = 0; E[i]; ++i){
        char c = E[i];
        if(c == '('){
            cnt.push(0);
            type.push(-1);
        }
        else if(c == ')'){
            int T = type.top(), C = cnt.top();
            type.pop(); cnt.pop();
            double temp = 0;
            for(int j = 0; j < C; ++j){
                temp += (T > 0 ? 1/S.top() : S.top());
                S.pop();
            }
            S.push(T > 0 ? 1/temp : temp);
            C = cnt.top();
            cnt.pop();
            cnt.push(C+1);
        }
        else if(c == '-'){
            type.pop();
            type.push(0);
        }
        else if(c == '|'){
            type.pop();
            type.push(1);
        }
        else{
            S.push(R[E[++i]-'1']);
            int temp = cnt.top();
            cnt.pop();
            cnt.push(temp+1);
        }
    }
    printf("%.6lf\n", S.top());
}