#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++){
		bool L = true;
		for(int i=0; i<10; i++){
			int n;
			scanf("%d", &n);
			if((n-1)%5 != i%5) L = false;
		}
		if(L) printf("%d\n", t);
	}
}