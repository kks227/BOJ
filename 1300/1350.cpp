#include <iostream>
using namespace std;

int main(){

	int N;
	int* val;
	cin >> N;
	val = new int[N];
	long long int cluster;
	long long int cnt = 0;
	long long int result;

	for(int i=0; i<N; i++)
		cin >> val[i];
	cin >> cluster;

	for(int i=0; i<N; i++){
		if(val[i] == 0) continue;
		if(val[i] % cluster) cnt++;
		cnt += val[i]/cluster;
	}

	result = cnt*cluster;
	cout << result << endl;

	return 0;
}