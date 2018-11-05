#include <cstdio>
#include <cstring>
#include <cctype>
#include <stack>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Node{
	int val;
	char op;
	bool type; // val: true, op: false
	Node(): Node(true, 0){}
	Node(bool type1, int val1): type(type1), val(val1){}
	Node(char op1): type(false), op(op1){}
};

char E[32], pc[8] = {'0', '1', '+', '-', '*', '=', '(', ')'};
unordered_map<char, int> C2I;
int N = 0, pn[8], L;
bool used[8];

int backtrack(int pos){
	if(pos == N){
		int s[2] = {0}, e[2] = {0, L}, ecnt = 0;
		char F[32] = {'\0',};
		for(int i = 0; E[i]; ++i){
			if(isalpha(E[i])) F[i] = pc[ pn[ C2I[E[i]] ] ];
			else F[i] = E[i];
			if(F[i] == '='){
				if(++ecnt == 2) break;
				e[0] = i;
				s[1] = i+1;
			}
		}
		if(ecnt != 1 || s[0] == e[0] || s[1] == e[1]) return 0;

		int fval[2];
		for(int k = 0; k < 2; ++k){

			stack<char> S1;
			vector<Node> P;
			bool recentVal = false;
			int scnt = 0;
			for(int i = s[k]; i < e[k]; ++i){
				if(F[i] == '('){
					if(recentVal) return 0;
					++scnt;
					S1.push('(');
					recentVal = false;
				}
				else if(F[i] == ')'){
					if(!recentVal || scnt == 0) return 0;
					while(S1.top() != '('){
						P.push_back(S1.top());
						S1.pop();
					}
					--scnt;
					S1.pop();
					recentVal = true;
				}
				else if(F[i] == '+'){
					if(!recentVal) return 0;
					while(!S1.empty() && S1.top() != '('){
						P.push_back(S1.top());
						S1.pop();
					}
					S1.push('+');
					recentVal = false;
				}
				else if(F[i] == '-'){
					if(recentVal){
						while(!S1.empty() && S1.top() != '('){
							P.push_back(S1.top());
							S1.pop();
						}
						S1.push('-');
					}
					else S1.push('_');
					recentVal = false;
				}
				else if(F[i] == '*'){
					if(!recentVal) return 0;
					while(!S1.empty() && S1.top() == '_'){
						P.push_back(S1.top());
						S1.pop();
					}
					S1.push('*');
					recentVal = false;
				}
				else{
					if(recentVal || F[i] == '0' && isdigit(F[i+1])) return 0;
					int k = F[i]-'0';
					for(; isdigit(F[i+1]); ++i)
						k = k*2 + F[i+1]-'0';
					P.push_back(Node(true, k));
					recentVal = true;
				}
			}
			if(!recentVal || scnt > 0) return 0;

			while(!S1.empty()){
				P.push_back(S1.top());
				S1.pop();
			}

			stack<int> S2;
			for(auto &p: P){
				if(p.type) S2.push(p.val);
				else{
					int b = S2.top(); S2.pop();
					if(p.op == '_') S2.push(-b);
					else{
						int a = S2.top(); S2.pop();
						if(p.op == '+') S2.push(a+b);
						else if(p.op == '-') S2.push(a-b);
						else S2.push(a*b);
					}
				}
			}
			fval[k] = S2.top();

		}
		return (fval[0] == fval[1]);
	}

	int result = 0;
	for(int i = 0; i < 8; ++i){
		if(used[i]) continue;
		used[i] = true;
		pn[pos] = i;
		result += backtrack(pos+1);
		used[i] = false;
	}
	return result;
}

int main(){
	scanf("%s", E);
	for(int i = 0; E[i]; ++i){
		if(!isalpha(E[i])) continue;
		if(C2I.find(E[i]) == C2I.end()) C2I[E[i]] = N++;
	}
	L = strlen(E);
	if(N > 8) puts("0");
	else printf("%d\n", backtrack(0));
}