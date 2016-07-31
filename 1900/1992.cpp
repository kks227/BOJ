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
	// 전체 영역이 모두 같은 값이면 압축 안 하고 함수 종료
	if(flag){
		cout << arr[i1][j1];
		return;
	}
	// 아닐 경우: 괄호 열고 영역을 다시 4등분하여 분할 정복
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
	// 분할 정복으로 답 출력
	getColorByRecursion(0, 0, N);
	cout << endl;
}