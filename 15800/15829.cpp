#include <cstdio>
using namespace std;
const int R = 31;
const int M = 1234567891;

int main(){
	int L;
	scanf("%d\n", &L);
	long long result = 0, r = 1;
	for(int i=0; i<L; i++){
		char c = getchar();
		result = (result + (c-'a'+1)*r) % M;
		r = r * R % M;
	}
	printf("%lld\n", result);
}