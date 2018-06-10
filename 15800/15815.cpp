#include <cstdio>
#include <cctype>
#include <stack>
using namespace std;

int main(){
	char E[101];
	scanf("%s", E);
	stack<int> S;
	for(int i=0; E[i]; i++){
		if(isdigit(E[i])) S.push(E[i]-'0');
		else{
			int b = S.top(); S.pop();
			int a = S.top(); S.pop();
			switch(E[i]){
			case '+': S.push(a+b); break;
			case '-': S.push(a-b); break;
			case '*': S.push(a*b); break;
			default : S.push(a/b); break;
			}
		}
	}
	printf("%d\n", S.top());
}