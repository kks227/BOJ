#include <iostream>
#include <string>
#include <cctype>
#include <stack>
#include <set>
using namespace std;
const bool tt[4][2][2] = {
	0, 0, 0, 1, // &
	0, 1, 1, 1, // |
	1, 1, 0, 1, // -->
	1, 0, 0, 1  // <->
};

struct Node{
	int vn, pos, type; // 5: variable, 4: unary, 0~3: binary
	Node* child[2];
	Node(): type(5){
		child[0] = child[1] = nullptr;
	}
	~Node(){
		if(child[0]) delete child[0];
		if(child[1]) delete child[1];
	}
};

string E, R;
int L, V2N[128], V, p;
bool val[26];
stack<int> S;
Node* root;

Node* parse();
void dfs(int vpos);
bool getResult(Node* node);

int main(){
	while(getline(cin, E)){
		L = E.size();

		set<char> vset;
		V = 0;
		for(char c: E)
			if(islower(c)) vset.insert(c);
		for(char c: vset)
			V2N[c] = V++;

		p = 0;
		root = parse();
		cout << E << endl;
		dfs(0);
		cout << endl;
		delete root;
	}
}



Node* parse(){
	Node* node = new Node;

	while(E[p] == ' ') p++;
	if(islower(E[p])){
		node->vn = V2N[E[p]];
		node->pos = p;
		node->type = 5;
		return node;
	}
	else p++;

	int ccnt = 0;
	for(; E[p] != ')'; p++){
		if(E[p] == ' ');
		else if(E[p] == '('){ // nested expression
			node->child[ccnt++] = parse();
		}
		else if(islower(E[p])){ // variable
			node->child[ccnt++] = parse();
		}
		else if(E[p] == '!'){ // unary !
			node->type = 4;
			node->pos = p;
		}
		else{ // binary
			if(E[p] == '&'){ // '&'
				node->type = 0;
				node->pos = p;
			}
			else if(E[p] == '|'){ // '|'
				node->type = 1;
				node->pos = p;
			}
			else if(E[p] == '-'){ // "-->"
				node->type = 2;
				while(E[++p] != '-');
				node->pos = p;
				while(E[++p] != '>');
			}
			else{ // "<->"
				node->type = 3;
				while(E[++p] != '-');
				node->pos = p;
				while(E[++p] != '>');
			}
		}
	}

	return node;
}

void dfs(int vpos){
	if(vpos == V){
		R = string(L, ' ');
		getResult(root);
		cout << R << endl;
		return;
	}

	dfs(vpos+1);
	val[vpos] = true;
	dfs(vpos+1);
	val[vpos] = false;
}

bool getResult(Node* node){
	bool result;
	switch(node->type){
	case 5: // variable
		result = val[node->vn]; break;

	case 4: // unary !
		result = !getResult(node->child[0]); break;

	default: // binary
		result = tt[node->type][ getResult(node->child[0]) ][ getResult(node->child[1]) ];
	}
	R[node->pos] = !!result + '0';
	return result;
}