#include <iostream>
using namespace std;

int main(){

	int M, N;
	cin >> M >> N;
	if(M > N){
		if(N == 1) cout << 0 << endl;
		else cout << (N-1)*2+1 << endl;
	}
	else cout << (M-1)*2 << endl;

	return 0;
}