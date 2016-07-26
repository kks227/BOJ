#include <cstdio>
using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int val;
		scanf("%x", &val);
		putchar(val < 32 ? '.' : '-');
	}
}