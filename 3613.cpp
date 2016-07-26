#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int main(){

	string id;
	cin >> id;
	int len = id.length();
	bool isJava = false;
	bool isCpp = false;

	if(!islower(id[0])){
		cout << "Error!" << endl;
		return 0;
	}
	for(int i=1; i<len; i++){
		if(id[i] == '_'){
			if(id[i-1] == '_' || i==len-1){
				cout << "Error!" << endl;
				return 0;
			}
			isCpp = true;
		}
		if(isupper(id[i])) isJava = true;
	}
	if(isJava && isCpp){
		cout << "Error!" << endl;
		return 0;
	}

	if(isJava){
		for(int i=0; i<len; i++){
			if(isupper(id[i])) cout << '_' << (char)(id[i]+32);
			else cout << id[i];
		}
	}
	else if(!isCpp) cout << id;
	else{
		for(int i=0; i<len; i++){
			if(id[i] == '_') cout << (char)(id[++i]-32);
			else cout << id[i];
		}
	}
	cout << endl;

	return 0;
}