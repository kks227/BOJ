#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <cctype>
using namespace std;

int main(){
	unordered_map<string, int> weight;
	while(1){
		string e;
		cin >> e;
		if(e == "END_OF_FIRST_PART") break;

		int w;
		cin >> w;
		weight[e] = w;
	}

	while(1){
		string M;
		cin >> M;
		if(M == "0") break;

		stack<int> S;
		S.push(0);
		bool unknown = false;
		for(int i = 0; i < M.size(); ++i){
			if(M[i] == '('){
				S.push(0);
			}
			else if(M[i] == ')'){
				int val = S.top(); S.pop();
				int temp = S.top(); S.pop();
				int k = M[++i]-'0';
				while(i+1 < M.size() && isdigit(M[i+1]))
					k = k*10 + M[++i]-'0';
				S.push(temp + val*k);
			}
			else{
				string e(1, M[i]);
				if(i+1 < M.size() && islower(M[i+1]))
					e.push_back(M[++i]);
				if(weight.find(e) == weight.end()){
					unknown = true;
					break;
				}
				int val = weight[e], k = 1;
				if(i+1 < M.size() && isdigit(M[i+1])){
					k = M[++i]-'0';
					while(i+1 < M.size() && isdigit(M[i+1]))
						k = k*10 + M[++i]-'0';
				}
				int temp = S.top(); S.pop();
				S.push(temp + val*k);
			}
		}
		if(unknown) cout << "UNKNOWN\n";
		else cout << S.top() << '\n';
	}
}