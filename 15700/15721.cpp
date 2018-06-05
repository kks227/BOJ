#include <cstdio>
using namespace std;

int main(){
	int A, T, B, cnt[2] = {0};
	scanf("%d %d %d", &A, &T, &B);
	for(int i=1; ; i++){
		if(++cnt[0] == T && !B) break;
		if(++cnt[1] == T && B) break;
		if(++cnt[0] == T && !B) break;
		if(++cnt[1] == T && B) break;
		bool flag = false;
		for(int j=0; j<=i; j++){
			if(++cnt[0] == T && !B){
				flag = true;
				break;
			}
		}
		if(flag) break;
		for(int j=0; j<=i; j++){
			if(++cnt[1] == T && B){
				flag = true;
				break;
			}
		}
		if(flag) break;
	}
	printf("%d\n", (cnt[0]+cnt[1]-1)%A);
}