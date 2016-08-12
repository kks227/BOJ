#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
	while(1){
		string code;
		getline(cin, code);
		if(code == "#") break;

		stack<string> S;
		bool legal = true;
		for(int i=0; i<code.size();){
			if(code[i] == '<'){
				string inner = code.substr(i+1, code.find('>', i)-i-1);
				string tagName = inner.substr(0, inner.find(' '));

				// closing tag
				if(inner[0] == '/'){
					tagName = tagName.substr(1);
					if(S.empty() || tagName != S.top()){
						legal = false;
						break;
					}
					S.pop();
				}
				// opening tag
				else if(inner.back() != '/') S.push(tagName);

				i += inner.size() + 2;
			}
			else i++;
		}
		if(!S.empty()) legal = false;
		puts(legal ? "legal" : "illegal");
	}
}