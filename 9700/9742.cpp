#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	string S;
	int K, fact[11] = {1, 1};
	for(int i=2; i<=10; i++)
		fact[i] = fact[i-1] * i;
	while(cin >> S >> K){
		string T = S;
		sort(T.begin(), T.end());
		cout << S << ' ' << K << " = ";
		if(fact[S.size()] < K) cout << "No permutation" << endl;
		else{
			for(int i=1; i<K; i++)
				next_permutation(T.begin(), T.end());
			cout << T << endl;
		}
	}
}