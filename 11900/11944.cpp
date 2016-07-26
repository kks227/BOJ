#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	string S, H;
	int N = 0, M;
	cin >> S >> M;
	for(char c: S)
		N = N*10 + c-'0';
	for(int i=0; i<N; i++) H += S;
	cout << H.substr(0, min(N*N, M)) << endl;
}