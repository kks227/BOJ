#include <iostream>
#include <vector>
using namespace std;
 
int main(){

	vector<int> prime;
	int i, j, prime_max;
	int A, B;
	cin >> A >> B;

	prime.push_back(2);
	for(i=3; i<=B; i+=2){
		prime_max = prime.size();
		for(j=0; j<prime_max; j++){
			if(i % prime[j] == 0) break;
		}
		if(j == prime_max) prime.push_back(i);
	}
	
	int result = 0;
	int cnt, temp;
	prime_max = prime.size();
	for(i=A; i<=B; i++){
		cnt = 0;
		temp = i;
		for(j=0; j<prime_max; j++){
			if(temp < prime[j]) break;
			while(temp % prime[j] == 0){
				temp /= prime[j];
				cnt++;
			}
		}
		for(j=0; j<prime_max; j++){
			if(cnt == prime[j]){
				result++;
				break;
			}
			else if(cnt < prime[j]){
				break;
			}
		}
	}

	cout << result << endl;

    return 0;
}