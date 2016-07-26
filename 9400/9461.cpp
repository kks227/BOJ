#include <iostream>
using namespace std;

int main(){

	unsigned long long p[100] = {1, 1, 1, 2, 2};
	for(int i=5; i<100; i++)
		p[i] = p[i-1] + p[i-5];
	int T, N;
	cin >> T;
	for(int i=0; i<T; i++){
		cin >> N;
		cout << p[N-1] << endl;
	}

	return 0;
}