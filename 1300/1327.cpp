#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

string reverse(string S){
	int len = S.length();
	string result = "";
	for(int i=len-1; i>=0; i--)
		result += S[i];
	return result;
}

int main(){

	int N, K, input;
	cin >> N >> K;
	string start = "", current, dest;
	for(int i=0; i<N; i++){
		cin >> input;
		start += input+'0';
	}
	dest = start;
	sort(dest.begin(), dest.end());
	set<string> visited;
	queue<string> BFSQ;
	int result = 0, qSize;
	BFSQ.push(start);
	while(!BFSQ.empty()){
		qSize = BFSQ.size();
		for(int i=0; i<qSize; i++){
			current = BFSQ.front();
			BFSQ.pop();
			if(current == dest){
				cout << result << endl;
				return 0;
			}
			if(visited.find(current) != visited.end()) continue;

			visited.insert(current);
			for(int j=0; j<=N-K; j++)
				BFSQ.push(current.substr(0, j) + reverse(current.substr(j, K)) + current.substr(j+K, N-j-K));
		}
		result++;
	}
	cout << -1 << endl;
	return 0;
}