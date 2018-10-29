#include <cstdio>
#include <cctype>
#include <stack>
using namespace std;

int main(){
	char E[18], P[17];
	int R, r0, r1, j = 0;
	scanf("%s %d", E, &R);

	stack<char> S1;
	for(int i = 0; E[i]; ++i){
		if(i%2 == 0) P[j++] = E[i];
		else if(E[i] == '+'){
			while(!S1.empty() && S1.top() == '*'){
				P[j++] = '*';
				S1.pop();
			}
			S1.push('+');
		}
		else S1.push('*');
	}
	while(!S1.empty()){
		P[j++] = S1.top();
		S1.pop();
	}
	stack<int> S2;
	for(int i = 0; E[i]; ++i){
		if(isdigit(P[i])) S2.push(P[i]-'0');
		else if(P[i] == '+'){
			int b = S2.top(); S2.pop();
			int a = S2.top(); S2.pop();
			S2.push(a+b);
		}
		else{
			int b = S2.top(); S2.pop();
			int a = S2.top(); S2.pop();
			S2.push(a*b);
		}
	}
	r0 = S2.top();

	r1 = E[0]-'0';
	for(int i = 1; E[i]; i += 2){
		if(E[i] == '+') r1 += E[i+1]-'0';
		else r1 *= E[i+1]-'0';
	}

	char result = 'I';
	if(r0 == R && r1 == R) result = 'U';
	else if(r0 == R) result = 'M';
	else if(r1 == R) result = 'L';
	putchar(result);
}