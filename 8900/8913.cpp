#include <iostream>
#include <string>
#include <map>
using namespace std;
typedef map<string, bool> M;

int L;
M dp;

bool epsilon(string S){
	M::iterator finder = dp.find(S);
	if(finder != dp.end()) return finder->second;
	if(S.size() == 0) return dp[S] = true;
	if(S.size() == 1) return dp[S] = false;

	bool ret = false;
	int p = 0, q;
	for(q=0; q<S.size(); q++){
		if(q==0 || S[q]!=S[q-1]){
			if(q-p > 1) ret |= epsilon(S.substr(0, p) + S.substr(q));
			p = q;
		}
	}
	if(q-p > 1) ret |= epsilon(S.substr(0, p));
	return dp[S] = ret;
}

int main(){
	int T;
	cin >> T;
	for(int t=0; t<T; t++){
		string S;
		cin >> S;
		cout << epsilon(S) << endl;
	}
}