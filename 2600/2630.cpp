#include <iostream>
using namespace std;

int arr[128][128];
int white, blue;

void getColorByRecursion(int i1, int j1, int size){
	if(size==1){
		if(arr[i1][j1] == 0) white++;
		else blue++;
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
		if(arr[i1][j1] == 0) white++;
		else blue++;
		return;
	}
	getColorByRecursion(i1, j1, size/2);
	getColorByRecursion(i1+size/2, j1, size/2);
	getColorByRecursion(i1, j1+size/2, size/2);
	getColorByRecursion(i1+size/2, j1+size/2, size/2);
}

int main(){

	int N;
	cin >> N;
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			cin >> arr[i][j];
	getColorByRecursion(0, 0, N);
	cout << white << endl << blue << endl;

    return 0;
}