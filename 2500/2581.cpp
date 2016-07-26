#include <iostream>
#include <cstring>
using namespace std;

int main(){

	int M, N;
	cin >> M >> N;
	bool* prime = new bool[N+1];
	memset(prime, 1, N+1);
	prime[1] = 0;
	for(int i=2; i<=N; i++){
		if(prime[i] == 0) continue;
		for(int j=2; i*j<=N; j++)
			prime[i*j] = 0;
	}

	int sum=0, min;
	for(int i=N; i>=M; i--){
		if(prime[i] == 0) continue;
		sum += i;
		min = i;
	}

	if(sum == 0) cout << -1 << endl;
	else cout << sum << endl << min << endl;

    return 0;
}