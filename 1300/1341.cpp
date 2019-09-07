#include <cstdio>
using namespace std;

int main(){
	long long a, b, k = 1, l = 0;
	scanf("%lld %lld", &a, &b);
	for(int i = 0; (l += k) % b != 0; k *= 2, ++i){
		if(i == 60){
			puts("-1");
			return 0;
		}
	}
	char result[61] = {'\0',};
	int r = 0;
	a *= l / b;
	while(k > 0){
		if(r == 60){
			puts("-1");
			return 0;
		}
		if(a >= k){
			result[r++] = '*';
			a -= k;
		}
		else result[r++] = '-';
		k /= 2;
	}
	puts(result);
}