#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
	map<string, int> M;
	int N, result = 0;
	cin >> N;
	for(int i=0; i<N; i++){
		string name;
		cin >> name;
		if(M.find(name) == M.end()) M[name] = 1;
		else{
			if(i < M[name]*2) result++;
			M[name]++;
		}
	}
	cout << result << endl;
}