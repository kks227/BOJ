#include <cstdio>
using namespace std;

int main(){
	int n;
	while(scanf("%d", &n) > 0){
		bool d[10] = {0};
		int cnt = 0, k = 0;
		while(cnt < 10){
			long long temp = 1LL*n*(++k);
			do{
				if(!d[temp%10]){
					d[temp%10] = true;
					cnt++;
				}
				temp /= 10;
			}while(temp);
		}
		printf("%d\n", k);
	}
}