#include <cstdio>
#include <stack>
using namespace std;

int main(){
	const int NOT[3] = {2, 1, 0};
	const int AND[3][3] = {0, 0, 0, 0, 1, 1, 0, 1, 2};
	const int OR[3][3] = {0, 1, 2, 1, 1, 2, 2, 2, 2};

	while(1){
		char I[81], P[81] = {0}; // Infix -> Postfix
		scanf("%s", I);
		if(I[0] == '.') break;

		stack<char> S;
		int pos = 0;
		for(int i=0; I[i]; i++){
			switch(I[i]){ // precedence: '+' < '*' < '-'
			case '+':
				while(!S.empty() && S.top() != '('){
					P[pos++] = S.top();
					S.pop();
				}
				S.push('+');
				break;
			case '*':
				while(!S.empty() && S.top() == '-'){
					P[pos++] = S.top();
					S.pop();
				}
				S.push('*');
				break;
			case '-':
				S.push('-');
				break;
			case '(':
				S.push('(');
				break;
			case ')':
				while(S.top() != '('){
					P[pos++] = S.top();
					S.pop();
				}
				S.pop();
				break;
			default:
				P[pos++] = I[i];
			}
		}
		while(!S.empty()){
			P[pos++] = S.top();
			S.pop();
		}

		int result = 0, a, b;
		for(int p=0; p<3; p++){
			for(int q=0; q<3; q++){
				for(int r=0; r<3; r++){
					for(int i=0; P[i]; i++){
						switch(P[i]){
						case 'P': S.push(p); break;
						case 'Q': S.push(q); break;
						case 'R': S.push(r); break;
						case '+':
							a = S.top(); S.pop();
							b = S.top(); S.pop();
							S.push(OR[a][b]);
							break;
						case '*':
							a = S.top(); S.pop();
							b = S.top(); S.pop();
							S.push(AND[a][b]);
							break;
						case '-':
							a = S.top(); S.pop();
							S.push(NOT[a]);
							break;
						default:
							S.push(P[i]-'0');
						}
					}
					if(S.top() == 2) result++;
					S.pop();
				}
			}
		}
		printf("%d\n", result);
	}
}