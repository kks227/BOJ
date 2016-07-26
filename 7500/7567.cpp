#include <iostream>
#include <string>
using namespace std;
 
int main(){

	string input;
	cin >> input;
	int height = 10;
	bool flag = input[0]=='('?true:false;

	int max = input.length();
	char current;
	for(int i=1; i<max; i++){
		current = input[i];
		if(current == '('){
			height += flag?5:10;
			flag = true;
		}
		else{
			height += flag?10:5;
			flag = false;
		}
	}
	cout << height << endl;
 
    return 0;
}