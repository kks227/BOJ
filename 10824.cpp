#include <cstdio>
using namespace std;

long long input(){
	bool flag = false;
	long long n = 0;
	while(1){
		int c = getchar();
		if(c<0 || c==' ' || c=='\n'){
			if(flag) return n;
			flag = true;
		}
		else n = n*10 + c-'0';
	}
	return -1;
}

int main(){
	printf("%lld\n", input()+input());
}