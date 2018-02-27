#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <unordered_map>
using namespace std;
const int UNKNOWN = -1;

struct Term{
	bool b;
	int o, v;
	Term *l, *r;
	Term(): b(false), o(-1), v(-1), l(nullptr), r(nullptr){}
	~Term(){
		if(v < 0){
			if(l) delete l;
			if(b && r) delete r;
		}
	}
};

class Parser{
public:
	int U, B;
	string E;
	//unordered_map<string, bool> isB;
	unordered_map<string, int> O;
	vector<vector<bool>> uTable;
	vector<vector<vector<bool>>> bTable;
	unordered_map<char, int> V;
	vector<int> D;
	Term *root;

	Parser(): U(0), B(0), root(nullptr){}
	~Parser();
	bool input();
	void makeParseTree();
	void getResult();

private:
	int pos, vcnt, tcnt, fcnt;
	Term* parse();
	void dfs(int vpos);
	int getValue(Term *term);
};

int main(){
	for(int t=1; ; t++){
		Parser Solver;
		if(!Solver.input()) break;
		cout << "Case " << t << ": ";
		Solver.getResult();
	}
}



Parser::~Parser(){
	if(root) delete root;
}

bool Parser::input(){
	cin >> U >> B;
	if(U < 0) return false;

	// unary operator
	for(int i=0; i<U; i++){
		string oprName;
		cin >> oprName;
		//isB[oprName] = false;
		O[oprName] = i;
		vector<bool> uRow;
		for(int x=0; x<2; x++){
			string tf;
			cin >> tf;
			uRow.push_back(tf == "true");
		}
		uTable.push_back(uRow);
	}

	// binary operator
	for(int i=0; i<B; i++){
		string oprName;
		cin >> oprName;
		//isB[oprName] = true;
		O[oprName] = i;
		vector<vector<bool>> bTb;
		for(int x=0; x<2; x++){
			vector<bool> bRow;
			for(int y=0; y<2; y++){
				string tf;
				cin >> tf;
				bRow.push_back(tf == "true");
			}
			bTb.push_back(bRow);
		}
		bTable.push_back(bTb);
	}

	// get an expression and parse
	cin.ignore(1024, '\n');
	getline(cin, E);
	makeParseTree();

	// initialization data
	while(1){
		char c;
		cin >> c;
		if(c == '*') break;
		string tf;
		cin >> tf;
		D[V[c]] = (tf == "true");
	}

	return true;
}

void Parser::makeParseTree(){
	pos = vcnt = 0;
	root = parse();
}

void Parser::getResult(){
	tcnt = fcnt = 0;
	dfs(0);
	if(tcnt > 0 && fcnt > 0)
		cout << "unknown" << endl;
	else if(tcnt > 0)
		cout << "true" << endl;
	else
		cout << "false" << endl;
}

Term* Parser::parse(){
	Term *term = new Term();

	for(; E[pos]==' '; pos++);

	// variable(terminal)
	if(islower(E[pos])){
		term->v = V[E[pos++]] = vcnt++;
		D.push_back(UNKNOWN);
		return term;
	}

	// '('
	for(pos++; E[pos]==' '; pos++);

	// left operand (if exists)
	if(!isupper(E[pos])){
		term->b = true;
		term->l = parse();
	}
	else term->b = false;

	// operator name
	for(; E[pos]==' '; pos++);
	int tpos = pos;
	for(; isupper(E[tpos]); tpos++);
	string oprName = E.substr(pos, tpos-pos);
	term->o = O[oprName];
	for(pos=tpos; E[pos]==' '; pos++);

	// right operand
	(term->b ? term->r : term->l) = parse();

	for(; E[pos]==' '; pos++);

	// ')'
	pos++;

	return term;
}

void Parser::dfs(int vpos){
	if(vpos == vcnt){
		(getValue(root) ? tcnt : fcnt)++;
		return;
	}

	if(D[vpos] == UNKNOWN){
		D[vpos] = 0;
		dfs(vpos+1);
		D[vpos] = 1;
		dfs(vpos+1);
		D[vpos] = UNKNOWN;
	}
	else dfs(vpos+1);
}

int Parser::getValue(Term *term){
	// variable(terminal)
	if(term->v >= 0) return D[term->v];

	if(term->b) // binary operator
		return bTable[term->o][getValue(term->l)][getValue(term->r)];
	else // unary operator
		return uTable[term->o][getValue(term->l)];
}