#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	int N, M, result = 0;
	scanf("%d %d", &N, &M);
	bool exist[10] = {0};
	for(int i=0; i<M; i++){
		int val;
		scanf("%d", &val);
		exist[val] = true;
	}
	int loop = 1;
	for(int i=0; i<N; i++)
		loop *= 10;
	for(int i=0; i<loop; i++){
		bool use[10] = {0};
		for(int j=0, n=i; j<N; j++){
			if(exist[n%10]) use[n%10] = true;
			n /= 10;
		}
		if(memcmp(exist, use, sizeof(use)) == 0) result++;
	}
	printf("%d\n", result);
}