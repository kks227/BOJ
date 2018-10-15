#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <cctype>
#include <cstdlib>
#include <unordered_map>
#include <algorithm>
#include <utility>
using namespace std;
const int MAX = 50;

enum TokenType { Literal, Variable, Operator };
enum StatementType { If, Else, EndIf, While, EndWhile, Assign, Output };
typedef pair<StatementType, int> StackNode;

struct Token{
	TokenType type;
	int val; // variable number or literal value;
	string op;
	Token(): Token(Literal, 0){}
	Token(TokenType type1, int val1): type(type1), val(val1){}
	Token(TokenType type1, string op1): type(type1), op(op1){}
};

typedef vector<Token> Postfix;

unordered_map<string, int> OpPrior;
int val[26];

Postfix getPostfix(const string &I){
	stack<string> S;
	Postfix P;
	bool recentIsVal = false;
	for(int i = 0; i < I.size(); ++i){
		if(I[i] == ' ' || I[i] == '\t') continue;

		if(isdigit(I[i])){ // immediate(literal)
			int val = I[i]-'0';
			while(i+1 < I.size() && isdigit(I[i+1])){
				val = val*10 + (I[++i]-'0');
			}
			P.push_back(Token(Literal, val));
			recentIsVal = true;
		}
		else if(islower(I[i])){ // variable
			P.push_back(Token(Variable, I[i]-'a'));
			recentIsVal = true;
		}
		else if(I[i] == '('){
			S.push("(");
			recentIsVal = false;
		}
		else if(I[i] == ')'){
			while(S.top() != "("){
				P.push_back(Token(Operator, S.top()));
				S.pop();
			}
			S.pop();
			recentIsVal = true;
		}
		else{
			string op = string(1, I[i]);
			if(I[i] == '!' || I[i] == '<' || I[i] == '>'){
				if(I[i+1] == '=') op += I[++i];
			}
			else if(I[i] == '=' || I[i] == '&' || I[i] == '|'){
				op += I[++i];
			}
			else if(I[i] == '-'){ // distinguish unary and binary -
				if(!recentIsVal) op = "-u";
			}
			recentIsVal = false;

			if(S.empty() || S.top() == "(") S.push(op);
			else{
				while(!S.empty() && S.top() != "("){
					int p = OpPrior[S.top()], q = OpPrior[op];
					if(p > q){
						P.push_back(Token(Operator, S.top()));
						S.pop();
					}
					else{
						if(p == q){ // left-to-right precedence
							if(S.top() != "-u" && S.top() != "!"){
								P.push_back(Token(Operator, S.top()));
								S.pop();
							}
						}
						break;
					}
				}
				S.push(op);
			}
		}
	}
	while(!S.empty()){
		P.push_back(Token(Operator, S.top()));
		S.pop();
	}
	return P;
}

int getResult(const Postfix &P){
	stack<int> S;
	for(int i = 0; i < P.size(); ++i){
		if(P[i].type == Literal){
			S.push(P[i].val);
		}
		else if(P[i].type == Variable){
			S.push(val[P[i].val]);
		}
		else{
			int a, b;
			if(P[i].op == "-u"){
				a = S.top(); S.pop();
				S.push(-a);
			}
			else if(P[i].op == "!"){
				a = S.top(); S.pop();
				S.push(!a);
			}
			else if(P[i].op == "*"){
				b = S.top(); S.pop();
				a = S.top(); S.pop();
				S.push(a*b);
			}
			else if(P[i].op == "/"){
				b = S.top(); S.pop();
				a = S.top(); S.pop();
				S.push(a/b);
			}
			else if(P[i].op == "%"){
				b = S.top(); S.pop();
				a = S.top(); S.pop();
				S.push(a%b);
			}
			else if(P[i].op == "+"){
				b = S.top(); S.pop();
				a = S.top(); S.pop();
				S.push(a+b);
			}
			else if(P[i].op == "-"){
				b = S.top(); S.pop();
				a = S.top(); S.pop();
				S.push(a-b);
			}
			else if(P[i].op == "<"){
				b = S.top(); S.pop();
				a = S.top(); S.pop();
				S.push(a<b);
			}
			else if(P[i].op == "<="){
				b = S.top(); S.pop();
				a = S.top(); S.pop();
				S.push(a<=b);
			}
			else if(P[i].op == ">"){
				b = S.top(); S.pop();
				a = S.top(); S.pop();
				S.push(a>b);
			}
			else if(P[i].op == ">="){
				b = S.top(); S.pop();
				a = S.top(); S.pop();
				S.push(a>=b);
			}
			else if(P[i].op == "=="){
				b = S.top(); S.pop();
				a = S.top(); S.pop();
				S.push(a==b);
			}
			else if(P[i].op == "!="){
				b = S.top(); S.pop();
				a = S.top(); S.pop();
				S.push(a!=b);
			}
			else if(P[i].op == "&&"){
				b = S.top(); S.pop();
				a = S.top(); S.pop();
				S.push(a&&b);
			}
			else if(P[i].op == "||"){
				b = S.top(); S.pop();
				a = S.top(); S.pop();
				S.push(a||b);
			}
			else{
				cout << P[i].op; // trap, we will never reach here
				exit(1);
			}
		}
	}
	return S.top();
}



int main(){
	OpPrior["-u"] = OpPrior["!"] = 6; // "-u" is unary -
	OpPrior["*"] = OpPrior["/"] = OpPrior["%"] = 5;
	OpPrior["+"] = OpPrior["-"] = 4;
	OpPrior["<"] = OpPrior["<="] = OpPrior[">"] = OpPrior[">="] = 3;
	OpPrior["=="] = OpPrior["!="] = 2;
	OpPrior["&&"] = 1;
	OpPrior["||"] = 0;

	while(1){
		int N;
		cin >> N;
		if(N == 0) break;

		cin.ignore(1024, '\n');
		vector<string> rawExpr;
		StatementType sType[MAX];
		Postfix expr[MAX];
		int setVarNum[MAX];
		for(int i = 0; i < N; ++i){
			string line;
			getline(cin, line);
			int j = 0;
			while(j < line.size() && (line[j] == ' ' || line[j] == '\t')) ++j;
			if(j+2 <= line.size() && line.substr(j, 2) == "if"){
				sType[i] = If;
				expr[i] = getPostfix(line.substr(j+2));
			}
			else if(j+4 <= line.size() && line.substr(j, 4) == "else"){
				sType[i] = Else;
			}
			else if(j+5 <= line.size() && line.substr(j, 5) == "while"){
				sType[i] = While;
				expr[i] = getPostfix(line.substr(j+5));
			}
			else if(j+3 <= line.size() && line.substr(j, 3) == "end"){
				j += 3;
				while(line[j] == ' ' || line[j] == '\t') ++j;
				if(line.substr(j, 2) == "if") sType[i] = EndIf;
				else sType[i] = EndWhile;
			}
			else if(j+3 <= line.size() && line.substr(j, 3) == "set"){
				sType[i] = Assign;
				j += 3;
				while(line[j] == ' ' || line[j] == '\t') ++j;
				setVarNum[i] = line[j++] - 'a';
				while(line[j] == ' ' || line[j] == '\t') ++j;
				expr[i] = getPostfix(line.substr(++j));
			}
			else{
				sType[i] = Output;
				expr[i] = getPostfix(line.substr(j+5));
			}
		}

		stack<StackNode> S;
		int jump[MAX]; // used when {if | while} condition is false, etc
		for(int i = 0; i < N; ++i){
			if(sType[i] == If){
				S.push(StackNode(If, i));
			}
			else if(sType[i] == Else){ // when we encounter Else without jump, go to EndIf
				jump[S.top().second] = i+1;
				S.pop();
				S.push(StackNode(Else, i));
			}
			else if(sType[i] == EndIf){
				jump[S.top().second] = i+1;
				S.pop();
			}
			else if(sType[i] == While){
				S.push(StackNode(While, i));
			}
			else if(sType[i] == EndWhile){
				jump[S.top().second] = i+1;
				jump[i] = S.top().second;
				S.pop();
			}
		}

		fill(val, val+26, 0);
		for(int i = 0; i < N;){
			if(sType[i] == If){
				if(!getResult(expr[i])) i = jump[i];
				else ++i;
			}
			else if(sType[i] == Else){
				i = jump[i];
			}
			else if(sType[i] == EndIf){
				++i;
			}
			else if(sType[i] == While){
				if(!getResult(expr[i])) i = jump[i];
				else ++i;
			}
			else if(sType[i] == EndWhile){
				i = jump[i];
			}
			else if(sType[i] == Assign){
				val[setVarNum[i]] = getResult(expr[i]);
				++i;
			}
			else{ // Output
				cout << getResult(expr[i]) << '\n';
				++i;
			}
		}
	}
}