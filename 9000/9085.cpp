#include <iostream>
using namespace std;
 
int main(){

	int T, N, sum, n;
	cin >> T;
	for(int i=0; i<T; i++){
		cin >> N;
		sum = 0;
		for(int j=0; j<N; j++){
			cin >> n;
			sum += n;
		}
		cout << sum << endl;
	}
 
    return 0;
}