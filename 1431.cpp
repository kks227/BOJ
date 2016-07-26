#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

bool compareSerialCode(string A, string B){
	if(A.length() != B.length()) return A.length() < B.length();
	int sumA = 0, sumB = 0;
	for(int i=0; i<A.length(); i++){
		if(isdigit(A[i])) sumA += A[i]-'0';
		if(isdigit(B[i])) sumB += B[i]-'0';
	}
	if(sumA != sumB) return sumA < sumB;
	return A < B;
}

int main(){

	int N;
	cin >> N;
	string code[1000];
	for(int i=0; i<N; i++)
		cin >> code[i];
	sort(code, code+N, compareSerialCode);
	for(int i=0; i<N; i++)
		cout << code[i] << endl;

	return 0;
}