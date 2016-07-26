#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	int T;
	cin >> T;
	for(int t=0; t<T; t++){
		int N, pos[1000];
		string key1[1000], key2[1000], C[1000];
		cin >> N;
		for(int i=0; i<N; i++)
			cin >> key1[i];
		for(int i=0; i<N; i++)
			cin >> key2[i];
		for(int i=0; i<N; i++)
			pos[i] = find(key2, key2+N, key1[i]) - key2;
		for(int i=0; i<N; i++)
			cin >> C[i];
		for(int i=0; i<N; i++)
			cout << C[pos[i]] << ' ';
		cout << endl;
	}
}