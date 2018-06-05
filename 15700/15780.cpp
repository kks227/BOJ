#include <cstdio>
using namespace std;

int main(){
	int N, K, cnt = 0;
	scanf("%d %d", &N, &K);
	for(int i=0; i<K; i++){
		int A;
		scanf("%d", &A);
		cnt += (A+1)/2;
	}
	puts(cnt>=N ? "YES" : "NO");
}