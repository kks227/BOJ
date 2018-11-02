#include <iostream>
#include <string>
#include <stack>
#include <unordered_set>
#include <cctype>
using namespace std;

inline void pass(string &D, int &pos){
	while(pos < D.size() && D[pos] == ' ') ++pos;
}

inline bool match(string &D, int &pos, char c){
	if(pos == D.size()) return false;
	return (D[pos++] == c);
}

bool wellFormed(string &D){
	int rcnt = 0, pos = 0;
	bool result = true;
	stack<string> S;
	unordered_set<string> tag;

	pass(D, pos);
	for(; pos < D.size(); ){
		if(D[pos++] != '<') continue;

		pass(D, pos);
		if(D[pos] == '/'){ // closing
			string tagName = "";
			++pos;
			pass(D, pos);
			for(; isalnum(D[pos]) || D[pos] == '-'; ++pos)
				tagName.push_back(D[pos]);
			pass(D, pos);
			if(!match(D, pos, '>')) return false;
			if(S.empty() || S.top() != tagName) return false;
			S.pop();
			tag.erase(tagName);
		}
		else{
			string tagName = "";
			for(; isalnum(D[pos]) || D[pos] == '-'; ++pos)
				tagName.push_back(D[pos]);
			pass(D, pos);

			unordered_set<string> attr;
			while(pos < D.size() && (isalnum(D[pos]) || D[pos] == '-')){
				string a;
				while(pos < D.size() && isalnum(D[pos]) || D[pos] == '-')
					a.push_back(D[pos++]);
				if(attr.find(a) != attr.end()) return false;
				attr.insert(a);

				pass(D, pos);
				if(!match(D, pos, '=')) return false;
				pass(D, pos);
				if(!match(D, pos, '\"')) return false;
				pass(D, pos);
				while(pos < D.size() && D[pos] != '\"') ++pos;
				if(!match(D, pos, '\"')) return false;
				pass(D, pos);
			}

			if(pos == D.size()) return false;
			if(tag.find(tagName) != tag.end()) return false;
			if(D[pos] == '/'){ // single
				++pos;
				pass(D, pos);
				if(!match(D, pos, '>')) return false;
				if(S.empty()) ++rcnt;
			}
			else if(!match(D, pos, '>')) return false;
			else{ // opening
				if(!S.empty() && tagName == S.top()) return false;
				if(S.empty()) ++rcnt;
				S.push(tagName);
				tag.insert(tagName);
			}
		}
	}

	if(rcnt != 1 || !S.empty()) return false;
	return true;
}

int main(){
	string line;
	getline(cin, line);
	for(bool breakFlag = false; !breakFlag; ){
		string D = "";
		while(1){
			getline(cin, line);
			if(line == "<?xml version=\"1.0\"?>") break;
			else if(line == "<?end?>"){
				breakFlag = true;
				break;
			}
			D.insert(D.end(), line.begin(), line.end());
		}
		D.push_back(' ');

		cout << (wellFormed(D) ? "" : "non ") << "well-formed\n";
	}
}