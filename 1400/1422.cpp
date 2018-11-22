#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	int K, N;
	string A[1000], result, chosen;
	cin >> K >> N;
	for(int i = 0; i < K; ++i){
		cin >> A[i];
		if(chosen.size() < A[i].size() || chosen.size() == A[i].size() && chosen < A[i]) chosen = A[i];
	}

	for(int i = 0; i < K-1; ++i)
		for(int j = K-2; j >= i; --j)
			if(A[j+1]+A[j] > A[j]+A[j+1]) swap(A[j], A[j+1]);
	int pos[1000];
	for(int i = 0; i < K; ++i){
		pos[i] = result.size();
		result += A[i];
	}
	for(int i = 0; i < K; ++i){
		int j = pos[i];
		if(result.substr(j, chosen.size()) <= chosen){
			cout << result.substr(0, j);
			for(int k = 0; k < N-K; ++k)
				cout << chosen;
			cout << result.substr(j) << '\n';
			break;
		}
	}
}