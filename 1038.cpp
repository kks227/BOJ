#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int cache[10][10];

int decrease(int n, int s){
	int& ret = cache[n-1][s];
	if(ret != -1) return ret;
	if(n == 1) return ret=1;
	ret = 0;
	for(int i=0; i<=s-1; i++){
		ret += decrease(n-1, i);
	}
	return ret;
}

void k_st_great_decrease(int n, int s, int k){
	if(n==1){
		cout << s;
		return;
	}
	for(int i=s-1; i>=0; i--){
		if(cache[n-2][i] < k) k -= cache[n-2][i];
		else{
			cout << s;
			k_st_great_decrease(n-1, i, k);
			return;
		}
	}
}

int main(){

	memset(cache, -1, sizeof(int)*100);
	int N, sum=0;
	cin >> N;
	for(int i=1; i<=10; i++){
		for(int j=0; j<10; j++){
			decrease(i, j);
			sum += cache[i-1][j];
			if(N < sum){
				k_st_great_decrease(i, j, sum-N);
				cout << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;

	return 0;
}