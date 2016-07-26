#include <iostream>
using namespace std;

int main(){

	int N, n;
	cin >> N;
	int *arr = new int[N];

	for(int i=0; i<N; i++){
		cin >> n;
		for(int j=0; j<n; j++)
			arr[i-j] = arr[i-j-1];
		arr[i-n] = i+1;
	}

	for(int i=0; i<N; i++){
		cout << arr[i];
		if(i < N-1) cout << ' ';
		else cout << endl;
	}

    return 0;
}