#include <iostream>
using namespace std;

int main(){

	int N, M;
	cin >> N >> M;

	int **arr = new int*[N];
	for(int i=0; i<N; i++){
		arr[i] = new int[M];
		for(int j=0; j<M; j++)
			cin >> arr[i][j];
	}

	int K, x1, x2, y1, y2;
	int sum;
	cin >> K;
	for(int k=0; k<K; k++){
		cin >> y1 >> x1 >> y2 >> x2;
		sum = 0;
		for(int i=y1-1; i<y2; i++)
			for(int j=x1-1; j<x2; j++)
				sum += arr[i][j];
		cout << sum << endl;
	}

	for(int i=0; i<N; i++)
		delete[] arr[i];
	delete[] arr;

    return 0;
}