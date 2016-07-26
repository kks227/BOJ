#include <iostream>
#include <string>
using namespace std;
 
int main(){

	int N;
	string input;
	cin >> N;
	int score, cnt, max;
	for(int i=0; i<N; i++){
		cin >> input;
		score = cnt = 0;
		max = input.length();
		for(int j=0; j<max; j++){
			if(input[j] == 'O'){
				cnt++;
				score += cnt;
			}
			else cnt = 0;
		}
		cout << score << endl;
	}
 
    return 0;
}