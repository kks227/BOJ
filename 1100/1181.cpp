#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool compareString(string A, string B){
	if(A.length() == B.length()) return A < B;
	return A.length() < B.length();
}

int main(){

	int N;
	cin >> N;
	vector<string> dictionary;
	vector<string>::iterator iter;
	string temp;
	for(int i=0; i<N; i++){
		cin >> temp;
		dictionary.push_back(temp);
	}
	sort(dictionary.begin(), dictionary.end(), compareString);
	temp = "";
	for(iter = dictionary.begin(); iter != dictionary.end(); iter++){
		if(temp == *iter) continue;
		cout << *iter << endl;
		temp = (*iter);
	}

    return 0;
}