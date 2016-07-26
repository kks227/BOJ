#include <iostream>
#include <cstdio>
using namespace std;

int main(){

	int T, s, n, p, q;
	int sum;
	scanf("%d", &T);
	for(int i=0; i<T; i++){
		scanf("%d", &s);
		sum = s;
		scanf("%d", &n);
		for(int j=0; j<n; j++){
			scanf("%d %d", &p, &q);
			sum += p*q;
		}
		cout << sum << endl;
	}

	return 0;
}