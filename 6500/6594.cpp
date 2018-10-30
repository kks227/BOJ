#include <cstdio>
#include <cctype>
#include <stack>
#include <vector>
using namespace std;

struct Node{
	bool type; // expression, operator
	int a, b;
	char op;
	Node(): Node('@'){}
	Node(char op1): type(true), op(op1){}
	Node(int a1, int b1): type(false), a(a1), b(b1){}
	Node operator +(const Node& O)const{ return Node(a+O.a, b+O.b); }
	Node operator -(const Node& O)const{ return Node(a-O.a, b-O.b); }
	Node operator *(const Node& O)const{ return Node(O.a == 0 ? a*O.b : O.a*b, b*O.b); }
};

int main(){
	char E[101];
	for(int t = 1; scanf("%s", E) > 0; ++t){
		Node F[2];
		for(int k = 0, i = 0; k < 2; ++k, ++i){
			vector<Node> P;
			stack<char> S1;
			for(; E[i] != '=' && E[i] != '\0'; ++i){
				if(isdigit(E[i])){
					int val = E[i]-'0';
					while(isdigit(E[i+1]))
						val = val*10 + E[++i]-'0';
					P.push_back(Node(0, val));
				}
				else if(E[i] == 'x'){
					P.push_back(Node(1, 0));
				}
				else if(E[i] == '('){
					S1.push('(');
				}
				else if(E[i] == ')'){
					while(S1.top() != '('){
						P.push_back(S1.top());
						S1.pop();
					}
					S1.pop();
				}
				else if(E[i] == '+'){
					while(!S1.empty() && (S1.top() == '*' || S1.top() == '-')){
						P.push_back(S1.top());
						S1.pop();
					}
					S1.push('+');
				}
				else if(E[i] == '-'){
					while(!S1.empty() && (S1.top() == '*' || S1.top() == '-')){
						P.push_back(S1.top());
						S1.pop();
					}
					S1.push('-');
				}
				else if(E[i] == '*'){
					S1.push('*');
				}
			}
			while(!S1.empty()){
				P.push_back(S1.top());
				S1.pop();
			}

			stack<Node> S2;
			for(auto &p: P){
				if(!p.type) S2.push(p);
				else{
					Node B = S2.top(); S2.pop();
					Node A = S2.top(); S2.pop();
					if(p.op == '+') S2.push(A + B);
					else if(p.op == '-') S2.push(A - B);
					else S2.push(A * B);
				}
			}
			F[k] = S2.top();
		}

		Node G = F[0] - F[1];
		printf("Equation #%d\n", t);
		if(G.a == 0){
			if(G.b == 0) puts("Infinitely many solutions.");
			else puts("No solution.");
		}
		else printf("x = %.6lf\n", -1.0*G.b/G.a);
		puts("");
	}
}