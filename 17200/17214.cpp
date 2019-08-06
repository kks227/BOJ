#include <iostream>
#include <string>
using namespace std;

inline int parseInt(string s){ return atoi(s.c_str()); }

int main(){
	string E;
	cin >> E;
	int c[2] = {0, 0};
	bool twoTerms = false;
	for(int i = E.size()-1; i > 0; --i){
		if(E[i] == '+' || E[i] == '-'){
			c[1] = parseInt(E.substr(0, i-1));
			c[0] = parseInt(E.substr(i+1)) * (E[i] == '-' ? -1 : 1);
			twoTerms = true;
			break;
		}
	}
	if(!twoTerms){
		if(E.back() == 'x') c[1] = parseInt(E.substr(0, E.size()-1));
		else c[0] = parseInt(E);
	}

	if(c[1] == 0 && c[0] == 0) cout << "W\n";
	else{
		if(c[1] != 0){
			if(c[1] == -2) cout << "-";
			else if(c[1] != 2) cout << c[1]/2;
			cout << "xx";
			if(c[0] > 0) cout << "+";
		}
		if(c[0] != 0){
			if(c[0] == -1) cout << "-";
			else if(c[0] == 1);
			else cout << c[0];
			cout << "x";
		}
		cout << "+W\n";
	}
}