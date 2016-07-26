#include <iostream>
#include <string>
using namespace std;

int main(){

	string input;
	getline(cin, input);

	int max = input.length();
	int count[26] = {0};
	char current;
	for(int i=0; i<max; i++){
		current = input[i];
		if(current < 'a') current += ('a'-'A');
		count[current-'a']++;
	}

	char max_char;
	max = 0;
	for(int i=0; i<26; i++){
		if(max < count[i]){
			max = count[i];
			max_char = 'A'+i;
		}
		else if(max == count[i])
			max_char = '?';
	}
	cout << max_char << endl;
 
    return 0;
}