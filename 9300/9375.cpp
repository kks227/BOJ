#include <iostream>
#include <string>
#include <utility>
#include <set>
#include <map>
using namespace std;

int main(){
	int T;
	cin >> T;
	for(int t=0; t<T; t++){
		int N;
		cin >> N;
		set<string> W;
		multimap<string, string> M;
		for(int i=0; i<N; i++){
			string A, B;
			cin >> A >> B;
			W.insert(B);
			M.insert(pair<string, string>(B, A));
		}
		int result = 1;
		for(auto& s: W)
			result *= M.count(s)+1;
		cout << result-1 << endl;
	}
}