#include <iostream>
using namespace std;

int main(){

	int C, K, result;
	cin >> C >> K;
	if(K==0) result = C;
	else{
		int S, T, pow10 = 1;
		for(int i=0; i<K; i++)
			pow10 *= 10;
		S = C / pow10;
		T = C % pow10 - C % (pow10/10);
		if(T>=5) result = (S+1)*pow10;
		else result = S*pow10;
	}
	cout << result << endl;

	return 0;
}