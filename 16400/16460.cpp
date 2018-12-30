#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	string userName, userPref;
	int maxGD, N;
	cin >> userName >> userPref >> maxGD >> N;
	bool flag[2] = {false,};
	for(char c: userPref)
		flag[c == 'F'] = true;
	vector<string> result;
	for(int i = 0; i < N; ++i){
		string name, gender;
		int gd;
		cin >> name >> gender >> gd;
		bool target = (gender == "F");
		if(flag[target] && gd <= maxGD) result.push_back(name);
	}
	sort(result.begin(), result.end());
	if(result.empty()) cout << "No one yet\n";
	else{
		for(string &s: result)
			cout << s << "\n";
	}
}