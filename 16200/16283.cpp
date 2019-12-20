#include <cstdio>
using namespace std;

int main(){
	int a, b, n, w, result = -1;
	scanf("%d %d %d %d", &a, &b, &n, &w);
	for(int i = 1; i < n; ++i){
		if(i*a + (n-i)*b == w){
			if(result != -1){
				result = -1;
				break;
			}
			result = i;
		}
	}
	if(result == -1) puts("-1");
	else printf("%d %d\n", result, n-result);
}