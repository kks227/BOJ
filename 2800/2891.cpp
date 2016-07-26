#include <cstdio>
using namespace std;

int main(){
	int N, S, R;
	bool broken[10] = {0}, spare[10] = {0};
	scanf("%d %d %d", &N, &S, &R);
	for(int i=0; i<S; i++){
		int n;
		scanf("%d", &n);
		broken[n-1] = true;
	}
	for(int i=0; i<R; i++){
		int n;
		scanf("%d", &n);
		spare[n-1] = true;
	}

	int result = 0;
	bool lend[10] = {0};
	for(int i=0; i<N; i++){
		if(!broken[i]) continue;
		if(spare[i]){
			lend[i] = true;
			continue;
		}

		bool borrow = false;
		if(i>0 && spare[i-1] && !lend[i-1]) lend[i-1] = borrow = true;
		else if(i<N-1 && spare[i+1] && !broken[i+1]) lend[i+1] = borrow = true;
		if(!borrow) result++;
	}
	printf("%d\n", result);
}