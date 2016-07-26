#include <iostream>
#include <string>
using namespace std;
  
int main(){

	string input;
	cin >> input;

	int n = 0, max = input.length();
	int current, multi = 1;
	for(int i=max-1; i>=0; i--){
		current = input[i];
		if(current >= 'A') current = current-'A'+10;
		else current -= '0';
		n += current*multi;
		multi *= 16;
	}
	cout << n << endl;
  
    return 0;
}