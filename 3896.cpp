#include <iostream>
#include <cstring>
using namespace std;

#define MAX 1299709

int main(){
 
    int T, k, cnt;
	bool *prime = new bool[MAX+1];
    memset(prime, 1, MAX+1);
    for(int i=2; i<=MAX; i++){
        if(!prime[i]) continue;
        for(int j=i*2; j<=MAX; j+=i)
            prime[j] = false;
    }

	cin >> T;
	for(int i=0; i<T; i++){
		cin >> k;
		if(prime[k] || k==1) cout << 0 << endl;
		else{
			cnt = 0;
			for(int j=k; !prime[j]; j--) cnt++;
			for(int j=k; !prime[j]; j++) cnt++;
			cout << cnt << endl;
		}
	}
	delete[] prime;

    return 0;
}