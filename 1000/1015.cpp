#include <iostream>
#include <algorithm>
using namespace std;

int main(){

	int A[50], B[50];
	int N, i, j;
	cin >> N;
	for(i=0; i<N; i++){
		cin >> A[i];
		B[i] = A[i];
	}

	sort(B, B+N);
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			if(A[i] == B[j]){
				cout << j;
				if(i<N-1) cout << ' ';
				else cout << endl;
				B[j] = 0;
				break;
			}
		}
	}

	return 0;
}