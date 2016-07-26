#include <cstdio>
#include <stack>
using namespace std;

int main(){
	unsigned long long N;
	scanf("%llu", &N);
	stack<bool> s;
	while(N){
		s.push(N%2);
		N /= 2;
	}
	while(!s.empty()){
		printf("%d", s.top());
		s.pop();
	}
}