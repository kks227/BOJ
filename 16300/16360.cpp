#include <iostream>
#include <string>
using namespace std;

int main(){
	int T;
	cin >> T;
	for(int t = 0; t < T; ++t){
		string S;
		cin >> S;
		int L = S.size();
		if(S[L-1] == 'n'){
			S.pop_back();
			S += "anes";
		}
		else if(S[L-2] == 'n' && S[L-1] == 'e'){
			S.pop_back();
			S.pop_back();
			S += "anes";
		}
		else if(S[L-1] == 'i' || S[L-1] == 'y'){
			S.pop_back();
			S += "ios";
		}
		else if(S[L-1] == 'l' || S[L-1] == 'r' || S[L-1] == 'v') S += "es";
		else if(S[L-1] == 't' || S[L-1] == 'w') S += "as";
		else if(S[L-1] == 'a' || S[L-1] == 'o' || S[L-1] == 'u') S += "s";
		else S += "us";
		cout << S << '\n';
	}
}