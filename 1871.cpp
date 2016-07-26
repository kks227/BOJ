#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){

	int N, front, rear;
	string S;
	cin >> N;
	for(int t=0; t<N; t++){
		cin >> S;
		front = 26*26*(S[0]-'A') + 26*(S[1]-'A') + S[2]-'A';
		rear = 1000*(S[4]-'0') + 100*(S[5]-'0') + 10*(S[6]-'0') + S[7]-'0';
		if(abs(front-rear) <= 100) cout << "nice" << endl;
		else cout << "not nice" << endl;
	}

	return 0;
}