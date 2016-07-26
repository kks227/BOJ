#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N;
		scanf("%d", &N);
		bool result = false;
		for(int b=2; b<=64; b++){
			string B = "";
			int n = N;
			while(n){
				B.push_back(n%b);
				n /= b;
			};
			string R = B;
			reverse(R.begin(), R.end());
			if(R == B){
				result = true;
				break;
			}
		}
		printf("%d\n", result);
	}
}