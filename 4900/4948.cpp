#include <iostream>
#include <cstring>
using namespace std;

int main(){
 
    int n;
    bool prime[246913];
    memset(prime, 1, 246913);
    for(int i=2; i<=246912; i++){
        if(!prime[i]) continue;
        for(int j=i*2; j<=246912; j+=i)
            prime[j] = false;
    }
	int count[246913]={0,}, prime_cnt=0;
	for(int i=2; i<=246912; i++){
		if(prime[i]) prime_cnt++;
		count[i] = prime_cnt;
	}

	while(1){
		cin >> n;
		if(n==0) break;
		cout << count[2*n]-count[n] << endl;
	}
 
    return 0;
}