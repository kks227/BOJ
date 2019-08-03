#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
const int MAX = 2500;

int main(){
	int N;
	unordered_map<string, int> H;
	cin >> N;
	for(int i = 0; i < N; ++i){
		string S;
		cin >> S;
		H[S] = i;
	}
	string S[MAX];
	int a = 0, b = 0;
	for(int i = 0; i < N; ++i){
		cin >> S[i];
		for(int j = 0; j < i; ++j){
			++b;
			if(H[S[j]] < H[S[i]]) ++a;
		}
	}
	cout << a << '/' << b;
}