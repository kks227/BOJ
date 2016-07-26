#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool isInsideByBinarySearch(string *arr, int size, string target){
    if(size == 1){
        if(target == arr[0]) return true;
        return false;
    }
    else if(size == 0) return false;
    int left = 0;
    int right = size-1;
    int mid;
    while(left <= right){
        mid = (left+right)/2;
        if(arr[mid] > target) right = mid-1;
        else if(arr[mid] < target) left = mid+1;
        else return true;
    }
    return false;
}

int main(){

	int N, M;
	string *neverSeen = new string[500000];
	string *neverSeenAndHeard = new string[500000];
	cin >> N >> M;
	for(int i=0; i<N; i++)
		cin >> neverSeen[i];

	sort(neverSeen, neverSeen+N);
	string input;
	int cnt = 0;
	for(int i=0; i<M; i++){
		cin >> input;
		if(isInsideByBinarySearch(neverSeen, N, input))
			neverSeenAndHeard[cnt++] = input;
	}

	if(cnt > 0) sort(neverSeenAndHeard, neverSeenAndHeard+cnt);
	cout << cnt << endl;
	for(int i=0; i<cnt; i++)
		cout << neverSeenAndHeard[i] << endl;

	delete[] neverSeen;
	delete[] neverSeenAndHeard;
    return 0;
}