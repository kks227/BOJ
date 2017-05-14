#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main(){
	int N, arr[1000];
	unordered_map<string, int> M;
	cin >> N;
	for(int i=0; i<N; i++){
		string S;
		cin >> S;
		M[S] = i;
	}
	for(int i=0; i<N; i++){
		string S;
		cin >> S;
		arr[i] = M[S];
	}
	int result = 0;
	for(int i=0; i<N-1; i++){
		bool flag = false;
		for(int j=i+1; j<N; j++){
			if(arr[i] > arr[j]){
				flag = true;
				break;
			}
		}
		if(flag) result++;
	}
	cout << result << endl;
}