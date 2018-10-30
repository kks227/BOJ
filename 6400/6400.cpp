#include <cstdio>
#include <cctype>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

enum NodeType{Literal, Variable, Operator};

struct Node{
	int k;
	char op;
	NodeType type;
	Node(): Node(Literal, 0){}
	Node(char op1): type(Operator), op(op1){}
	Node(NodeType type1, int k1): type(type1), k(k1){}
};

int main(){
	int val[26] = {0}, old[26] = {0};
	while(1){
		char E[1000];
		gets_s(E);
		if(E[0] == '#') break;

		stack<char> S1;
		vector<Node> P;
		for(int i = 0; E[i]; ++i){
			char c = E[i];
			if(c == ' ') continue;
			else if(isdigit(c)){
				int val = c-'0';
				while(isdigit(E[i+1]))
					val = val*10 + E[++i]-'0';
				P.push_back(Node(Literal, val));
			}
			else if(isupper(c)){
				P.push_back(Node(Variable, c-'A'));
			}
			else if(c == '('){
				S1.push('(');
			}
			else if(c == ')'){
				while(S1.top() != '('){
					P.push_back(S1.top());
					S1.pop();
				}
				S1.pop();
			}
			else if(c == '_'){
				S1.push('_');
			}
			else{
				while(!S1.empty() && S1.top() == '_'){
					P.push_back('_');
					S1.pop();
				}
				S1.push(c);
			}
		}
		while(!S1.empty()){
			P.push_back(S1.top());
			S1.pop();
		}

		stack<Node> S2;
		for(auto &p: P){
			if(p.type == Literal || p.type == Variable) S2.push(p);
			else{
				Node A, B;
				int a, b;
				if(p.op == '_'){
					A = S2.top(); S2.pop();
					a = A.type == Literal ? A.k : val[A.k];
					S2.push(Node(Literal, -a));
				}
				else{
					B = S2.top(); S2.pop();
					b = B.type == Literal ? B.k : val[B.k];
					A = S2.top(); S2.pop();
					a = A.type == Literal ? A.k : val[A.k];
					if(p.op == '='){
						val[A.k] = b;
						S2.push(Node(Literal, b));
					}
					else if(p.op == '+'){
						S2.push(Node(Literal, a+b));
					}
					else if(p.op == '-'){
						S2.push(Node(Literal, a-b));
					}
					else if(p.op == '*'){
						S2.push(Node(Literal, a*b));
					}
					else{ // '/'
						S2.push(Node(Literal, a/b));
					}
				}
			}
		}
		
		bool changed[26] = {false,};
		int ccnt = 0;
		for(int i = 0; i < 26; ++i){
			if(old[i] != val[i]){
				old[i] = val[i];
				changed[i] = true;
				++ccnt;
			}
		}
		if(ccnt == 0) puts("No Change");
		else{
			for(int i = 0; i < 26; ++i){
				if(!changed[i]) continue;
				printf("%c = %d%s", 'A'+i, val[i], --ccnt > 0 ? ", " : "\n");
			}
		}
	}
}