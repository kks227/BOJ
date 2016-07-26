#include <iostream>
#include <algorithm>
using namespace std;

int main(){

	int T;
	int N[5];
	cin >> T;
	for(int i=0; i<T; i++){
		for(int j=0; j<5; j++)
			cin >> N[j];
		sort(N, N+5);
		if(N[3]-N[1] >= 4) cout << "KIN" << endl;
		else cout << N[1]+N[2]+N[3] << endl;
	}

	return 0;
}