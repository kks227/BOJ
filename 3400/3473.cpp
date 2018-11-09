#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <utility>
#include <cctype>
using namespace std;
typedef pair<char, string> Node;

int main(){
	int T;
	cin >> T;
	for(int t = 0; t < T; ++t){
		string E;
		cin >> E;
		stack<char> S1;
		vector<char> P;
		for(char c: E){
			if(c == '('){
				S1.push('(');
			}
			else if(c == ')'){
				while(S1.top() != '('){
					P.push_back(S1.top());
					S1.pop();
				}
				S1.pop();
			}
			else if(c == '+'){
				while(!S1.empty() && S1.top() != '('){
					P.push_back(S1.top());
					S1.pop();
				}
				S1.push('+');
			}
			else if(c == '-'){
				while(!S1.empty() && S1.top() != '('){
					P.push_back(S1.top());
					S1.pop();
				}
				S1.push('-');
			}
			else if(c == '*'){
				while(!S1.empty() && (S1.top() == '*' || S1.top() == '/')){
					P.push_back(S1.top());
					S1.pop();
				}
				S1.push('*');
			}
			else if(c == '/'){
				while(!S1.empty() && (S1.top() == '*' || S1.top() == '/')){
					P.push_back(S1.top());
					S1.pop();
				}
				S1.push('/');
			}
			else{
				P.push_back(c);
			}
		}
		while(!S1.empty()){
			P.push_back(S1.top());
			S1.pop();
		}
		
		stack<Node> S2;
		for(char c: P){
			if(islower(c)){
				S2.push(Node(' ', string(1, c)));
			}
			else{
				Node A[2];
				A[1] = S2.top(); S2.pop();
				A[0] = S2.top(); S2.pop();
				bool pflag[2] = {false,};
				if(c == '+'){
				}
				else if(c == '-'){
					if(A[1].first == '+' || A[1].first == '-') pflag[1] = true;
				}
				else if(c == '*'){
					for(int k = 0; k < 2; ++k)
						if(A[k].first == '+' || A[k].first == '-') pflag[k] = true;
				}
				else{
					for(int k = 0; k < 2; ++k)
						if(A[k].first == '+' || A[k].first == '-') pflag[k] = true;
					if(A[1].first == '*' || A[1].first == '/') pflag[1] = true;
				}

				string temp[2] = {A[0].second, A[1].second};
				for(int k = 0; k < 2; ++k)
					if(pflag[k]) temp[k] = "(" + temp[k] + ")";
				Node C(c, temp[0] + string(1, c) + temp[1]);
				S2.push(C);
			}
		}
		cout << S2.top().second << '\n';
	}
}