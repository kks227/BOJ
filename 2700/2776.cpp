#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int isInsideByBinarySearch(int *arr, int size, int target){
	if(size == 1){
		if(target == arr[0]) return 1;
		return 0;
	}
	else if(size == 0) return 0;
	int left = 0;
	int right = size-1;
	int mid;
	while(left <= right){
		mid = (left+right)/2;
		if(arr[mid] > target) right = mid-1;
		else if(arr[mid] < target) left = mid+1;
		else return 1;
	}
	return 0;
}

int main(){

	int T, N, M;
	int *note;
	int target;
	scanf("%d", &T);
	for(int i=0; i<T; i++){
		scanf("%d", &N);
		note = new int[N];
		for(int j=0; j<N; j++)
			scanf("%d", &note[j]);
		sort(note, note+N);
		
		scanf("%d", &M);
		for(int j=0; j<M; j++){
			scanf("%d", &target);
			printf("%d\n", isInsideByBinarySearch(note, N, target));
		}
	}

    return 0;
}