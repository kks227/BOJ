#include <iostream>
using namespace std;

int main(){

	int N, K;
	cin >> N >> K;
	int cnt = 0;
	bool arr[1001] = {0};

	for(int i=2; i<=N; i++){
		if(arr[i]) continue;
		for(int j=i; j<=N; j+=i){
			if(arr[j]) continue;
			cnt++;
			if(cnt == K){
				cout << j << endl;
				return 0;
			}
			arr[j] = true;
		}
	}

	return 0;
}