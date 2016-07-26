#include <iostream>
using namespace std;

int main(){

	int N, K;
	cin >> N >> K;

	int cnt = 0;
	int i;
	for(i=1; i<=N; i++){
		if(N%i == 0){
			cnt++;
			if(cnt == K) break;
		}
	}

	if(i > N) i=0;
	cout << i << endl;

    return 0;
}