#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, L, H[1000];
	scanf("%d %d", &N, &L);
	for(int i = 0; i < N; ++i)
		scanf("%d", H+i);
	sort(H, H+N);
	int result = L;
	for(int i = 0; i < N; ++i){
		if(result >= H[i]) ++result;
		else break;
	}
	printf("%d\n", result);
}