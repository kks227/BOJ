#include <cstdio>
#include <stack>
using namespace std;

int main(){
	int m, n;
	scanf("%d %d", &m, &n);
	stack<char> S;
	do{
		int d = m%n;
		if(d < 10) S.push(d+'0');
		else S.push(d-10+'A');
		m /= n;
	}while(m);
	while(!S.empty()){
		putchar(S.top());
		S.pop();
	}
}