#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <unordered_map>
using namespace std;

int main(){
	unordered_map<int, int> val[128];
	int cap[128], lcnt = 0, result = 0;
	while(1){
		string line;
		getline(cin, line);
		if(line == "."){
			if(lcnt == 0) break;
			cout << result << '\n';
			for(int i = 0; i < 26; ++i){
				val['A' + i].clear();
				val['a' + i].clear();
			}
			fill(cap, cap+128, 0);
			lcnt = result = 0;
			continue;
		}
		++lcnt;
		if(result > 0) continue;

		int pos = 0, k = 0, arr = line[0];
		stack<int> S;
		S.push(arr);
		for(pos = 2; ; ){
			if(isdigit(line[pos])){
				k = 0;
				while(isdigit(line[pos]))
					k = k*10 + line[pos++]-'0';
			}
			else if(line[pos] == ']'){
				++pos;
				if(S.size() == 1) break;
				if(k >= cap[S.top()] || val[S.top()].find(k) == val[S.top()].end()){
					result = lcnt;
					break;
				}
				k = val[S.top()][k];
				S.pop();
			}
			else{
				S.push(line[pos]);
				pos += 2;
			}
		}

		if(pos == line.size()){
			val[arr].clear();
			cap[arr] = k;
		}
		else if(k >= cap[arr]) result = lcnt;
		else{
			++pos;
			int l = 0;
			for(; pos < line.size(); ){
				if(isdigit(line[pos])){
					l = 0;
					while(pos < line.size() && isdigit(line[pos]))
						l = l*10 + line[pos++]-'0';
				}
				else if(line[pos] == ']'){
					if(l >= cap[S.top()] || val[S.top()].find(l) == val[S.top()].end()){
						result = lcnt;
						break;
					}
					l = val[S.top()][l];
					S.pop();
					++pos;
				}
				else{
					S.push(line[pos]);
					pos += 2;
				}
			}
			if(result == 0) val[arr][k] = l;
		}
	}
}