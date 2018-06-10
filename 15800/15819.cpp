#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	int N, I;
	string S[100];
	cin >> N >> I;
	for(int i=0; i<N; i++)
		cin >> S[i];
	sort(S, S+N);
	cout << S[I-1] << endl;
}