#include <iostream>
#include <cctype>
#include <string>
#include <stack>
using namespace std;

int main(){

	string infix;
	cin >> infix;
	int max = infix.size();
	stack<char> opr;
	for(int i=0; i<max; i++){
		switch(infix[i]){
		case '+':
		case '-':
			if(opr.empty() || opr.top()=='(');
			else{
				while(!opr.empty() && opr.top()!='('){
					cout << opr.top();
					opr.pop();
				}
			}
			opr.push(infix[i]);
			break;
		case '*':
		case '/':
			if(opr.empty() || opr.top()=='(' || opr.top()=='+' || opr.top()=='-');
			else{
				while(!opr.empty() && opr.top()!='(' && (opr.top()=='*' || opr.top()=='/')){
					cout << opr.top();
					opr.pop();
				}
			}
			opr.push(infix[i]);
			break;
		case '(':
			opr.push('(');
			break;
		case ')':
			while(opr.top() != '('){
				cout << opr.top();
				opr.pop();
			}
			opr.pop();
			break;
		default:
			cout << infix[i];
		}
	}
	while(!opr.empty()){
		cout << opr.top();
		opr.pop();
	}
	cout << endl;

	return 0;
}