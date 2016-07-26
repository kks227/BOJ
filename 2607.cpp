#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main(){

	int alp[100][26] = {0};
	int N, wsize;
	cin >> N;
	string word;
	for(int i=0; i<N; i++){
		cin >> word;
		wsize = word.size();
		for(int j=0; j<wsize; j++)
			alp[i][word[j]-'A']++;
	}

	int result = 0;
	bool flag, plus, minus;
	for(int i=1; i<N; i++){
		flag = true;
		plus = minus = false;
		for(int j=0; j<26; j++){
			if(abs(alp[0][j] - alp[i][j]) > 1){
				flag = false;
				break;
			}
			else if(alp[0][j] - alp[i][j] == 1){
				if(minus){
					flag = false;
					break;
				}
				minus = true;
			}
			else if(alp[0][j] - alp[i][j] == -1){
				if(plus){
					flag = false;
					break;
				}
				plus = true;
			}
		}
		if(flag) result++;
	}
	cout << result << endl;

	return 0;
}