#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int main(){
	string gen[2] = {"A", "B"};
	vector<string> del;
	string target;
	while(1){
		string type, X, Y, dummy;
		cin >> type >> X;
		type.pop_back();
		if(type == "gen"){
			cin >> dummy >> Y;
			gen[X[0]-'A'] = Y;
		}
		else if(type == "del")
			del.push_back(X);
		else{
			target = X;
			break;
		}
	}

	queue<string> Q;
	unordered_set<string> visited;
	Q.push("A");
	visited.insert("A");
	for(int i = 0; i < 10; ++i){
		int qSize = Q.size();
		for(int j = 0; j < qSize; ++j){
			string curr = Q.front(), temp, next; Q.pop();
			for(char c: curr)
				temp += gen[c-'A'];
			vector<bool> erased(temp.size(), false);
			for(int k = 0; k < temp.size(); ++k){
				for(string &s: del){
					if(k + s.size() > temp.size()) continue;
					bool flag = true;
					for(int l = 0; l < s.size(); ++l)
						if(temp[k+l] != s[l]) flag = false;
					if(flag){
						for(int l = 0; l < s.size(); ++l)
							erased[k+l] = true;
					}
				}
			}
			for(int k = 0; k < temp.size(); ++k)
				if(!erased[k]) next.push_back(temp[k]);
			if(visited.find(next) == visited.end()){
				visited.insert(next);
				Q.push(next);
			}
		}

		if(visited.find(target) != visited.end()){
			cout << "O\n";
			return 0;
		}
	}
	cout << "X\n";
}