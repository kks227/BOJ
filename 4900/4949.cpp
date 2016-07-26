#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
	while(1){
		string line;
		getline(cin, line);
		if(line == ".") break;

		stack<bool> S;
		bool fail = false;
		for(char c: line){
			if(c == '(') S.push(false);
			else if(c == ')'){
				if(S.empty() || S.top()){
					fail = true;
					break;
				}
				S.pop();
			}
			else if(c == '[') S.push(true);
			else if(c == ']'){
				if(S.empty() || !S.top()){
					fail = true;
					break;
				}
				S.pop();
			}
		}
		if(!S.empty()) fail = true;
		cout << (fail ? "no" : "yes") << endl;
	}
}