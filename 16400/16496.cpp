#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	int N;
	string A[1000], result;
	cin >> N;
	bool flag = false;
	for(int i = 0; i < N; ++i){
		cin >> A[i];
		if(A[i] != "0") flag = true;
	}
	if(!flag){
		cout << "0\n";
		return 0;
	}
	for(int i = 0; i < N-1; ++i)
		for(int j = N-2; j >= i; --j)
			if(A[j+1]+A[j] > A[j]+A[j+1]) swap(A[j], A[j+1]);
	for(int i = 0; i < N; ++i)
		result += A[i];
	cout << result << '\n';
}