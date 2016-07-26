#include <iostream>
#include <cstring>
using namespace std;

#define MAX 1000
#define LIMIT 31

int main(){

	bool prime[MAX+1];
	memset(prime, 1, MAX+1);
	prime[1] = false;
	for(int i=4; i<=MAX; i+=2)
		prime[i] = false;
	for(int i=3; i<=LIMIT; i+=2){
		if(prime[i]){
			for(int j=i*i; j<=MAX; j+=i)
				prime[j] = false;
		}
	}

	int N, input, result=0;
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> input;
		if(prime[input]) result++;
	}
	cout << result << endl;

	return 0;
}