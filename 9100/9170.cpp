#include <cstdio>
#include <stack>
#include <vector>
using namespace std;
const int MAX = 1000;

int main(){
	char E[MAX+1];
	while(scanf("%s", E) > 0){
		vector<int> P;
		stack<char> S1;
		bool recentVal = false;
		for(int i = 0; E[i]; ++i){
			if(E[i] == '('){
				S1.push('(');
				recentVal = false;
			}
			else if(E[i] == ')'){
				while(!S1.empty() && S1.top() != '('){
					P.push_back(S1.top());
					S1.pop();
				}
				S1.pop();
				recentVal = true;
			}
			else if(E[i] == '+'){
				if(!recentVal); // unary '+'
				else{
					while(!S1.empty() && S1.top() != '('){
						P.push_back(S1.top());
						S1.pop();
					}
					S1.push('+');
				}
				recentVal = false;
			}
			else if(E[i] == '-'){
				if(!recentVal) S1.push('~'); // unary '-'
				else{
					while(!S1.empty() && S1.top() != '('){
						P.push_back(S1.top());
						S1.pop();
					}
					S1.push('-');
				}
				recentVal = false;
			}
			else if(E[i] == '*'){
				S1.push('*');
				recentVal = false;
			}
			else{
				P.push_back(E[i]);
				recentVal = true;
			}
		}
		while(!S1.empty()){
			P.push_back(S1.top());
			S1.pop();
		}

		stack<int> S2;
		for(char c: P){
			int a, b;
			if(c == '~'){
				a = S2.top(); S2.pop();
				S2.push(-a);
			}
			else if(c == '+'){
				b = S2.top(); S2.pop();
				a = S2.top(); S2.pop();
				S2.push(a+b);
			}
			else if(c == '-'){
				b = S2.top(); S2.pop();
				a = S2.top(); S2.pop();
				S2.push(a-b);
			}
			else if(c == '*'){
				b = S2.top(); S2.pop();
				a = S2.top(); S2.pop();
				S2.push(a*b);
			}
			else S2.push(c-'0');
		}
		printf("%d\n", S2.top());
	}
}