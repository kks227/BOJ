#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int N;
	cin >> N;
	vector<string> A;
	for(int i=0; i<N; i++){
		string L, W = "";
		cin >> L;
		for(int i=0; i<L.size(); i++){
			if(isdigit(L[i])){
				if(W == "0") W[0] = L[i];
				else W.push_back(L[i]);
			}
			else if(W.size() > 0){
				A.push_back(W);
				W = "";
			}
		}
		if(W.size() > 0) A.push_back(W);
	}
	sort(A.begin(), A.end(), [](const string &s, const string &t){
		if(s.size() != t.size()) return s.size() < t.size();
		return s < t;
	});
	for(auto &s: A)
		cout << s << endl;
}