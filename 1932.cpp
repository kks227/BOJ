#include <iostream>
using namespace std;

int main(){

	int N;
	cin >> N;
	int **sum = new int*[N];
	for(int i=0; i<N; i++)
		sum[i] = new int[i+1];
	for(int i=0; i<N; i++){
		for(int j=0; j<=i; j++){
			cin >> sum[i][j];
		}
	}
	int maxsum = sum[0][0];
	for(int i=1; i<N; i++){
		for(int j=0; j<=i; j++){
			if(j == 0) sum[i][j] += sum[i-1][j];
			else if(j == i) sum[i][j] += sum[i-1][j-1];
			else{
				if(sum[i-1][j-1] > sum[i-1][j]) sum[i][j] += sum[i-1][j-1];
				else sum[i][j] += sum[i-1][j];
			}
		}
	}
	for(int i=0; i<N; i++){
		if(maxsum < sum[N-1][i]) maxsum = sum[N-1][i];
	}
	cout << maxsum << endl;

	for(int i=0; i<N; i++)
		delete[] sum[i];
	delete[] sum;
	return 0;
}