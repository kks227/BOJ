#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <cctype>
#include <cassert>
using namespace std;

enum NodeType{Literal, Variable, Operator};

struct Node{
	int val;
	string var;
	char op;
	NodeType type;
	Node(): Node(0){}
	Node(NodeType type1, int val1): type(type1), val(val1){}
	Node(string var1): type(Variable), var(var1){}
	Node(char op1): type(Operator), op(op1){}
};
typedef vector<Node> Postfix;

unordered_map<string, Postfix> expr;
unordered_map<string, int> val;
unordered_set<string> visited;

bool dfs(string curr){
	stack<int> S;
	for(auto &p: expr[curr]){
		if(p.type == Literal) S.push(p.val);
		else if(p.type == Variable){
			string next = p.var;
			if(expr.find(next) == expr.end()) return false;
			if(visited.find(next) != visited.end()){
				if(val.find(next) == val.end()) return false;
				else S.push(val[next]);
			}
			else{
				visited.insert(next);
				if(!dfs(next)) return false;
				S.push(val[next]);
			}
		}
		else{
			int b = S.top(); S.pop();
			if(p.op == '_') S.push(-b);
			else{
				int a = S.top(); S.pop();
				if(p.op == '+') S.push(a+b);
				else if(p.op == '-') S.push(a-b);
				else S.push(a*b);
			}
		}
	}
	val[curr] = S.top();
	return true;
}



int main(){
	string line;
	while(getline(cin, line)){
		while(line[0] == ' ') line.erase(line.begin());
		while(!line.empty() && line.back() == ' ') line.pop_back();
		if(line.empty()) continue;

		if(line.substr(0, 6) == "PRINT "){
			int pos = 6;
			while(line[pos] == ' ') ++pos;
			string var = line.substr(pos);
			if(expr.find(var) == expr.end()) cout << "UNDEF\n";
			else{
				visited.clear();
				val.clear();
				if(!dfs(var)) cout << "UNDEF\n";
				else cout << val[var] << '\n';
			}
		}
		else if(line == "RESET"){
			expr.clear();
		}
		else{
			int pos = 1;
			while(isalnum(line[pos])) ++pos;
			string var = line.substr(0, pos);
			while(line[pos] == ' ') ++pos;
			pos += 2;

			stack<char> S;
			Postfix P;
			bool recentVal = false;
			for(; pos < line.size(); ++pos){
				char c = line[pos];
				if(c == ' ') continue;

				if(c == '('){
					S.push('(');
					recentVal = false;
				}
				else if(c == ')'){
					while(!S.empty() && S.top() != '('){
						P.push_back(S.top());
						S.pop();
					}
					S.pop();
					recentVal = true;
				}
				else if(c == '+'){
					while(!S.empty() && S.top() != '('){
						P.push_back(S.top());
						S.pop();
					}
					S.push('+');
					recentVal = false;
				}
				else if(c == '-'){
					if(recentVal){
						while(!S.empty() && S.top() != '('){
							P.push_back(S.top());
							S.pop();
						}
						S.push('-');
					}
					else S.push('_');
					recentVal = false;
				}
				else if(c == '*'){
					while(!S.empty() && S.top() == '_'){
						P.push_back(S.top());
						S.pop();
					}
					S.push('*');
					recentVal = false;
				}
				else if(isdigit(c)){ // literal
					string lit(1, c);
					while(pos+1 < line.size()){
						if(isdigit(line[pos+1])) lit.push_back(line[pos+1]);
						else break;
						++pos;
					}
					P.push_back( Node(Literal, stoi(lit)) );
					recentVal = true;
				}
				else{ // variable
					string lit(1, c);
					while(pos+1 < line.size()){
						if(isalnum(line[pos+1])) lit.push_back(line[pos+1]);
						else break;
						++pos;
					}
					P.push_back(lit);
					recentVal = true;
				}
			}
			while(!S.empty()){
				P.push_back(S.top());
				S.pop();
			}

			expr[var] = P;
		}
	}
}