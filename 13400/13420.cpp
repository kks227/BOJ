#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		long long A, B, C;
		char o1, o2;
		scanf("%lld %c %lld %c %lld", &A, &o1, &B, &o2, &C);
		bool result = false;
		if(o1 == '='){
			if(o2 == '+' && A == B+C) result = true;
			if(o2 == '-' && A == B-C) result = true;
			if(o2 == '*' && A == B*C) result = true;
			if(o2 == '/' && A == B/C) result = true;
		}
		else{
			if(o1 == '+' && A+B == C) result = true;
			if(o1 == '-' && A-B == C) result = true;
			if(o1 == '*' && A*B == C) result = true;
			if(o1 == '/' && A/B == C) result = true;
		}
		puts(result ? "correct" : "wrong answer");
	}
}