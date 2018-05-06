#include <cstdio>
using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	for(int i=1; ; i++){
		if(1+i+i*i == N){
			printf("%d\n", i);
			break;
		}
	}
}