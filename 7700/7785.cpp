#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main(){
	int N;
	unordered_set<string> S;
	cin >> N;
	for(int i = 0; i < N; ++i){
		string name, q;
		cin >> name >> q;
		if(q[0] == 'e') S.insert(name);
		else S.erase(S.find(name));
	}
	vector<string> result;
	for(const string &s: S)
		result.push_back(s);
	sort(result.begin(), result.end());
	for(int i = result.size()-1; i >= 0; --i)
		cout << result[i] << '\n';
}