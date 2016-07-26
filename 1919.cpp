#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){

	string A, B;
	cin >> A >> B;
	int A_len, B_len;
	A_len = A.length();
	B_len = B.length();
	int A_char[26] = {0}, B_char[26] = {0};
	int result = 0;

	for(int i=0; i<A_len; i++) A_char[A[i]-'a']++;
	for(int i=0; i<B_len; i++) B_char[B[i]-'a']++;
	for(int i=0; i<26; i++) result += abs(A_char[i] - B_char[i]);
	cout << result << endl;

	return 0;
}