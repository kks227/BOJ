#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	int N, M = 0, K, P[8];
	string S[8];
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> S[i];
		P[i] = i;
		M += S[i].size();
	}
	cin >> K;

	int result = 0;
	do{
		string A, B;
		for(int i=0; i<N; i++)
			B += S[P[i]];
		A = B + B;

		int p[160] = {0}, cnt = 0, j = 0;
		for(int i=1; i<M; i++){
			while(j > 0 && B[i] != B[j]) j = p[j-1];
			if(B[i] == B[j]) p[i] = ++j;
		}
		j = 0;
		for(int i=0; i<M*2-1; i++){
			while(j > 0 && A[i] != B[j]) j = p[j-1];
			if(A[i] == B[j]){
				if(j == M-1){
					cnt++;
					j = p[j];
				}
				else j++;
			}
		}
		if(cnt == K) result++;
	}while(next_permutation(P, P+N));
	cout << result << endl;
}