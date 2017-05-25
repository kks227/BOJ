#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main(){
	int R, C, K, result = 0;
	map<string, int> M;
	cin >> R >> C;
	for(int i=0; i<R; i++){
		string line;
		cin >> line;
		auto finder = M.find(line);
		if(finder == M.end()) M[line] = 1;
		else finder->second++;
	}
	cin >> K;
	for(auto &p: M){
		string line = p.first;
		int k = p.second, cnt = 0;
		for(char c: line)
			if(c == '0') cnt++;
		if(cnt <= K && cnt%2 == K%2) result = max(result, k);
	}
	cout << result << endl;
}