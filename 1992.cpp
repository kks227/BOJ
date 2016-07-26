#include <iostream>
#include <cstdio>
using namespace std;

int arr[64][64];

void getColorByRecursion(int i1, int j1, int size){
	if(size==1){
		cout << arr[i1][j1];
		return;
	}
	bool flag = true;
	int i2 = i1+size;
	int j2 = j1+size;
	for(int i=i1; i<i2; i++){
		for(int j=j1; j<j2; j++){
			if(arr[i1][j1] != arr[i][j]){
				flag = false;
				break;
			}
		}
	}
	if(flag){
		cout << arr[i1][j1];
		return;
	}
	cout << '(';
	getColorByRecursion(i1, j1, size/2);
	getColorByRecursion(i1, j1+size/2, size/2);
	getColorByRecursion(i1+size/2, j1, size/2);
	getColorByRecursion(i1+size/2, j1+size/2, size/2);
	cout << ')';
}

int main(){

	int N;
	cin >> N;
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			scanf("%1d", &arr[i][j]);
	getColorByRecursion(0, 0, N);
	cout << endl;

	return 0;
}