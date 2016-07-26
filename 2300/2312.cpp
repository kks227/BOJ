#include <iostream>
#include <vector>
using namespace std;

int main(){

	int T, N;
	cin >> T;
	bool sieve[100001] = {0, 0, 1};
	for(int i=3; i<=100000; i++){
		if(i%2) sieve[i] = true;
		else sieve[i] = false;
	}
	for(int i=3; i<100000; i+=2){
		if(sieve[i] == false) continue;
		for(int j=i*2; j<=100000; j+=i) sieve[j] = false;
	}
	vector<int> factor;
	vector<int>::iterator iter;
	for(int i=2; i<100000; i++){
		if(sieve[i] == true) factor.push_back(i);
	}

	int cnt, fact;
	for(int i=0; i<T; i++){
		cin >> N;
		for(iter = factor.begin(); iter != factor.end(); iter++){
			cnt = 0;
			fact = *iter;
			while(N%fact == 0){
				N /= fact;
				cnt++;
			}
			if(cnt) cout << fact << ' ' << cnt << endl;
			if(N == 1) break;
		}
	}

    return 0;
}