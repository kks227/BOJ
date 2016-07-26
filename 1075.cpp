#include <iostream>
using namespace std;
  
int main(){

	int N, F;
	cin >> N >> F;

	int mod, orig, temp, result;
	mod = N % F;
	orig = N % 100;

	if(N < 100) result = 0;
	else if(F == 1) result = 0;
	else if(orig-mod < 0) result = orig-mod+F;
	else{
		temp = orig-mod;
		while(temp >= 0){
			temp -= F;
		}
		result = temp+F;
	}

	if(result < 10) cout << 0 << result << endl;
	else cout << result << endl;

    return 0;
}