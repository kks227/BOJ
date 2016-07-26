#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 488895;

int main(){
	char N[7], H[488895];
	scanf("%s", N);
	int p = 0, len = strlen(N), cnt = 1;
	for(int i=1; i<=100000; i++){
		if(i==10 || i==100 || i==1000 || i==10000 || i==100000) cnt++;
		int n = i;
		for(int j=0; n>0; j++){
			H[p+cnt-j-1] = n%10 + '0';
			n /= 10;
		}
		p += cnt;
	}
	for(int i=0; i<488895; i++){
		bool find = true;
		for(int j=0; j<len; j++)
			if(H[i+j] != N[j]){
				find = false;
				break;
			}
		if(find){
			printf("%d\n", i+1);
			break;
		}
	}
}