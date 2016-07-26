#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int cache[2001];
string word;
int len;

int palindrome(int n){
	int& ret = cache[n];
	if(ret) return ret;
	if(n == len) return (ret = 0);
	if(n == len-1) return (ret = 1);

	bool flag;
	ret = 1 + palindrome(n+1);
	for(int i=1; n+i<len; i++){
		if(word[n] == word[n+i]){
			flag = true;
			for(int j=1; j<=i/2; j++){
				if(word[n+j] != word[n+i-j]){
					flag = false;
					break;
				}
			}
			if(flag) ret = min(ret, 1 + palindrome(n+i+1));
		}
	}
	return ret;
}

int main(){

	cin >> word;
	len = word.length();
	cout << palindrome(0) << endl;

	return 0;
}