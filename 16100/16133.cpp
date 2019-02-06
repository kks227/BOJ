#include <cstdio>
#include <cctype>
#include <cmath>
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;

struct Node{
	char op;
	long long val;
	bool type;
	Node(): Node('_'){}
	Node(char op1): op(op1), type(false){}
	explicit Node(long long val1): val(val1), type(true){}
};

long long power(long long a, long long b){
	if(b == 0) return 1;
	if(b == 1) return a;
	long long result = power(a, b/2);
	result *= result;
	if(b%2) result *= a;
	return result;
}

long long intSqrt(long long a){
	if(a <= 1) return a;
	long long lo = 0, hi = (long long)sqrt(a) + 1;
	while(lo+1 < hi){
		long long mid = (lo+hi)/2;
		(mid*mid <= a ? lo : hi) = mid;
	}
	return lo;
}

int main(){
	unordered_map<char, int> opP;
	opP['#'] = 0;
	opP['^'] = 1;
	opP['*'] = opP['/'] = 2;
	opP['+'] = opP['-'] = 3;

	char E[101];
	scanf("%s", E);
	stack<char> S1;
	vector<Node> P;
	for(int i = 0; E[i] != '='; ++i){
		char c = E[i];
		if(c == '(') S1.push('(');
		else if(c == ')'){
			while(S1.top() != '('){
				P.push_back(S1.top());
				S1.pop();
			}
			S1.pop();
		}
		else if(isdigit(c)){
			long long val = c - '0';
			while(isdigit(E[i+1]))
				val = val*10 + E[++i] - '0';
			P.push_back(Node(val));
		}
		else{
			while(!S1.empty()){
				char d = S1.top();
				if(d == '(' || opP[d] > opP[c] || opP[d] == opP[c] && opP[d] <= 1) break;
				P.push_back(S1.top());
				S1.pop();
			}
			S1.push(c);
		}
	}
	while(!S1.empty()){
		P.push_back(S1.top());
		S1.pop();
	}

	stack<long long> S2;
	for(auto &p: P){
		if(p.type) S2.push(p.val);
		else{
			if(opP[p.op] >= 1){
				long long b = S2.top(); S2.pop();
				long long a = S2.top(); S2.pop();
				long long c;
				if(p.op == '^') c = power(a, b);
				else if(p.op == '+') c = a + b;
				else if(p.op == '-') c = a - b;
				else if(p.op == '*') c = a * b;
				else{
					int sign = ((a >= 0) == (b >= 0) ? 1 : -1);
					a = abs(a); b = abs(b);
					c = a / b * sign;
				}
				S2.push(c);
			}
			else{
				long long a = S2.top(); S2.pop();
				S2.push(intSqrt(a));
			}
		}
	}
	printf("%lld\n", S2.top());
}