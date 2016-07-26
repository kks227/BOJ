#include <iostream>
#include <cstring>
using namespace std;

int main(){

	int T, N;
	unsigned long long pig[6], next[6], sum;
	cin >> T;
	for(int i=0; i<T; i++){
		cin >> N;
		sum = 0;
		for(int j=0; j<6; j++){
			cin >> pig[j];
			sum += pig[j];
		}
		if(sum > N){
			cout << 1 << endl;
			continue;
		}

		for(int day=2; ; day++){
			sum = 0;
			for(int j=0; j<6; j++){
				next[j] = pig[j] + pig[(j+5)%6] + pig[(j+1)%6] + pig[(j+3)%6];
				sum += next[j];
			}
			if(sum > N){
				cout << day << endl;
				break;
			}
			memcpy(pig, next, sizeof(unsigned long long)*6);
		}
	}

	return 0;
}