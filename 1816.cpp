#include <iostream>
#include <cstring>
using namespace std;

int main(){

	int N;
	long long S;
	cin >> N;
	bool prime[1000001];
	memset(prime, 1, 1000001);
	for(int i=2; i<=1000000; i++){
		if(!prime[i]) continue;
		for(int j=i*2; j<=1000000; j+=i)
			prime[j] = false;
	}

	bool flag;
	for(int i=0; i<N; i++){
		cin >> S;
		flag = true;
		for(long long j=2; j<=1000000; j++){
			if(prime[j] && S%j==0){
				flag = false;
				break;
			}
		}
		cout << (flag?"YES":"NO") << endl;
	}

	return 0;
}