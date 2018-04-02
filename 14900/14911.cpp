#include <iostream>
#include <sstream>
#include <string>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

int main(){
	string line;
	getline(cin, line);
	stringstream ss(line);
	int A[10], N = 0, S;
	while(!ss.eof()){ ss >> A[N++]; }
	cin >> S;

	set<P> result;
	for(int i=0; i<N-1; i++)
		for(int j=i+1; j<N; j++)
			if(A[i]+A[j] == S) result.insert( P(min(A[i], A[j]), max(A[i], A[j])) );
	for(auto &p: result)
		cout << p.first << ' ' << p.second << endl;
	cout << result.size() << endl;
}