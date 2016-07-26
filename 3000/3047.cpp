#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){

	int arr[3];
	for(int i=0; i<3; i++)
		cin >> arr[i];
	sort(arr, arr+3);
	string S;
	cin >> S;
	for(int i=0; i<3; i++)
		cout << arr[S[i]-'A'] << ' ';

	return 0;
}