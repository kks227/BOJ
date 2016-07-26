#include <iostream>
using namespace std;

int main(){

	int N;
	cin >> N;
	if(N==4 || N==7 || N==8) cout << -1 << endl;
	else{
		int cnt = 0;
		while((N-cnt*3)%5 != 0) cnt++;
		cout << cnt + (N-cnt*3)/5 << endl;
	}

	return 0;
}