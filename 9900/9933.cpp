#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int main(){
	int N;
	string result;
	set<string> P;
	cin >> N;
	for(int i=0; i<N; i++){
		string W, R;
		cin >> W;
		R = W;
		reverse(R.begin(), R.end());
		if(W == R) result = W;
		else{
			set<string>::iterator finder = P.find(R);
			if(finder != P.end()) result = W;
		}
		P.insert(W);
	}
	cout << result.size() << ' ' << result[result.size()/2] << endl;
}