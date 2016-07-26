#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

int main(){

	set<int> A;
	int m, n, u=0, val;
	cin >> m >> n;
	for(int i=0; i<m; i++){
		scanf("%d", &val);
		A.insert(val);
	}
	for(int j=0; j<n; j++){
		scanf("%d", &val);
		if( A.find(val) != A.end() ) u++;
	}
	cout << m+n-2*u << endl;

	return 0;
}