#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(){

	string S, temp;
	int len;
	bool innerFlag, outerFlag;
	set<string> check;
	while(1){
		cin >> S;
		if(S[0] == '*') break;
		len = S.length();

		outerFlag = true;
		for(int i=1; i<len; i++){
			innerFlag = true;
			for(int j=0; j+i<len; j++){
				temp = S[j];
				temp += S[j+i];
				if(check.find(temp) != check.end()){
					innerFlag = false;
					break;
				}
				check.insert(temp);
			}
			check.clear();
			if(!innerFlag){
				outerFlag = false;
				break;
			}
		}
		cout << S << " is " << (outerFlag?"":"NOT ") << "surprising." << endl;
	}

	return 0;
}