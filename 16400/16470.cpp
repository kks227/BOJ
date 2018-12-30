#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main(){
	int N = 0;
	string C;
	unordered_map<string, int> cnt;
	while(cin >> C){
		++N;
		if(cnt.find(C) == cnt.end()) cnt[C] = 1;
		else ++cnt[C];
	}
	double result = 1;
	for(auto p: cnt)
		result -= (1.0*p.second/N)*(1.0*p.second/N);
	cout << result << "\n";
}