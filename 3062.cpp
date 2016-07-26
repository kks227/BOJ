#include <iostream>
using namespace std;

int reverse(int n){
	int result = 0;
	while(n){
		result *= 10;
		result += n%10;
		n /= 10;
	}
	return result;
}

bool isSymmetric(int n){
	return n==reverse(n);
}

int main(){

	int T, N, R;
	cin >> T;
	for(int i=0; i<T; i++){
		cin >> N;
		R = reverse(N);
		if(isSymmetric(N+R)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}