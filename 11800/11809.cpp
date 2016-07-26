#include <cstdio>
using namespace std;

int main(){
	int N, M, n = 0, m = 0, p = 1000000000;
	bool f1 = false, f2 = false, init = true;
	scanf("%d %d", &N, &M);
	for(int i=0; i<10; i++){
		if(init){
			if(N/p==0 && M/p==0){
				N %= p;
				M %= p;
				p /= 10;
				continue;
			}
			else init = false;
		}

		if(N/p == M/p){
			n = n*10 + N/p;
			m = m*10 + M/p;
			f1 = f2 = true;
		}
		else if(N/p > M/p){
			n = n*10 + N/p;
			f1 = true;
		}
		else{
			m = m*10 + M/p;
			f2 = true;
		}
		N %= p;
		M %= p;
		p /= 10;
	}
	if(f1) printf("%d\n", n);
	else puts("YODA");
	if(f2) printf("%d\n", m);
	else puts("YODA");
}