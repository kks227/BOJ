#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	string str[1000];
	cin >> str[0];
	int len = str[0].size();
	for(int i=1; i<len; i++)
		str[i] = str[0].substr(i);
	sort(str, str+len);
	for(int i=0; i<len; i++)
		cout << str[i] << endl;
}