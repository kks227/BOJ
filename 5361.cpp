#include <iostream>
using namespace std;
 
int main(){
 
	unsigned long long cost[5] = {35034, 23090, 19055, 12530, 18090};
	unsigned long long result;
	int N, n;
	cin >> N;
	for(int i=0; i<N; i++){
		result = 0;
		for(int j=0; j<5; j++){
			cin >> n;
			result += n*cost[j];
		}
		cout << '$' << result/100 << '.';
		result %= 100;
		if(result < 10) cout << 0;
		cout << result << endl;
	}
 
    return 0;
}