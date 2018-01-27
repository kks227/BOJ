#include <cstdio>
using namespace std;

int main(){
	int N, U = 0, cnt[1001] = {0}, result[1000], j = 0;
	bool fail = false;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int a;
		scanf("%d", &a);

		if(fail) continue;
		else if(a == 0) U++;
		else if(a > 0) cnt[a]++;
		else{
			if(cnt[-a] > 0) cnt[-a]--;
			else if(j < U) result[j++] = -a;
			else fail = true;
		}
	}

	if(fail) puts("No");
	else{
		puts("Yes");
		for(int i=0; i<j; i++)
			printf("%d ", result[i]);
		for(int i=j; i<U; i++)
			printf("1 ");
	}
}