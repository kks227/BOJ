#include <cstdio>
using namespace std;

int main(){
	int N;
	scanf("%d\n", &N);
	int s = 0, e;
	for(e = 0; e < N; ++e){
		if(e == N-1 || getchar() == 'R'){
			for(int i = e; i >= s; --i)
				printf("%d\n", i+1);
			s = e+1;
		}
	}
}