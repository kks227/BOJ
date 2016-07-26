#include <iostream>
#include <string>
#include <cctype>
using namespace std;

#define EOS '$'

class expr;
class term;
class factor;
class value;

class expr{
public:
	bool isUnary;
	term *T;
	expr *E;
};

class term{
public:
	bool isUnary;
	factor *F;
	term *T;
};

class factor{
public:
	bool isValue;
	union{
		expr *E;
		value *V;
	};
};

class value{
public:
	string name;
};

string input, output;
int len, current;

void parseExpr(expr *curE);
void parseTerm(term *curT);
void parseFactor(factor *curF);
void parseValue(value *curV);

void extractExpr(expr *curE);
void extractTerm(term *curT);
void extractFactor(factor *curF);
void extractValue(value *curV);

int main(){

	expr *root = new expr;
	while(cin >> input){
		input.push_back(EOS);
		len = input.length();
		current = 0;
		parseExpr(root);

		output = "";
		extractExpr(root);
		cout << output << endl;
	}
 
    return 0;
}

void parseExpr(expr *curE){
	//cout << "EXPRESSION" << endl;
	term *newT = new term;
	parseTerm(newT);
	curE->T = newT;
	if(input[current] == '+'){
		current++;
		curE->isUnary = false;
		expr *newE = new expr;
		parseExpr(newE);
		curE->E = newE;
	}
	else{
		curE->isUnary = true;
		curE->E = '\0';
	}
}

void parseTerm(term *curT){
	//cout << "TERM" << endl;
	factor *newF = new factor;
	parseFactor(newF);
	curT->F = newF;
	if(input[current] == '(' || islower(input[current])){
		curT->isUnary = false;
		term *newT = new term;
		parseTerm(newT);
		curT->T = newT;
	}
	else{
		curT->isUnary = true;
		curT->T = '\0';
	}
}

void parseFactor(factor *curF){
	//cout << "FACTOR" << endl;
	if(input[current] == '('){
		curF->isValue = false;
		current++;
		expr *newE = new expr; 
		parseExpr(newE);
		curF->E = newE;
		current++;
	}
	else{
		curF->isValue = true;
		value *newV = new value;
		parseValue(newV);
		curF->V = newV;
	}
}

void parseValue(value *curV){
	curV->name = "";
	while(islower(input[current]))
		(curV->name).push_back(input[current++]);
	//cout << "VALUE: " << curV->name << endl;
}

void extractExpr(expr *curE){
	expr *tempE;
	term *tempT = curE->T;
	factor *tempF;
	while(1){
		if(!tempT->isUnary){
			extractTerm(tempT);
			break;
		}
		tempF = tempT->F;
		if(tempF->isValue){
			extractValue(tempF->V);
			break;
		}
		tempE = tempF->E;
		if(!tempE->isUnary){
			extractExpr(tempE);
			break;
		}
		tempT = tempE->T;
	}

	if(!curE->isUnary){
		output.push_back('+');
		tempE = curE->E;
		while(1){
			if(!tempE->isUnary){
				extractExpr(tempE);
				break;
			}
			tempT = tempE->T;
			if(!tempT->isUnary){
				extractTerm(tempT);
				break;
			}
			tempF = tempT->F;
			if(tempF->isValue){
				extractValue(tempF->V);
				break;
			}
			tempE = tempF->E;
		}
	}
}

void extractTerm(term *curT){
	expr *tempE;
	term *tempT;
	factor *tempF = curT->F;
	while(1){
		if(tempF->isValue){
			extractValue(tempF->V);
			break;
		}
		tempE = tempF->E;
		if(!tempE->isUnary){
			output.push_back('(');
			extractExpr(tempE);
			output.push_back(')');
			break;
		}
		tempT = tempE->T;
		if(!tempT->isUnary){
			extractTerm(tempT);
			break;
		}
		tempF = tempT->F;
	}

	if(!curT->isUnary){
		tempT = curT->T;
		while(1){
			if(!tempT->isUnary){
				extractTerm(tempT);
				break;
			}
			tempF = tempT->F;
			if(tempF->isValue){
				extractValue(tempF->V);
				break;
			}
			tempE = tempF->E;
			if(!tempE->isUnary){
				output.push_back('(');
				extractExpr(tempE);
				output.push_back(')');
				break;
			}
			tempT = tempE->T;
		}
	}
}

void extractFactor(factor *curF){
	expr *tempE;
	term *tempT;
	factor *tempF = curF;
	bool flag = true;
	while(!tempF->isValue){
		tempE = tempF->E;
		if(!tempE->isUnary){
			flag = false;
			break;
		}
		tempT = tempE->T;
		if(!tempT->isUnary){
			flag = false;
			break;
		}
		tempF = tempT->F;
	}
	if(flag) extractValue(tempF->V);
	else{
		output.push_back('(');
		extractExpr(tempF->E);
		output.push_back(')');
	}
}

void extractValue(value *curV){
	output.append(curV->name);
	//cout << "VALUE ACCEPTED: " << curV->name << endl;
}