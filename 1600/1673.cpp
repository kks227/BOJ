#include <cstdio>
using namespace std;

int main(){
	int n, k;
	while(scanf("%d %d", &n, &k) > 0){
		int result = n, stamp = n;
		while(stamp >= k){
			int temp = stamp / k;
			result += temp;
			stamp = stamp % k + temp;
		}
		printf("%d\n", result);
	}
}