#include <cstdio>
using namespace std;

int main(){
	int N, X = 0;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		int P;
		scanf("%d", &P);
		X ^= P;
	}
	puts(X ? "koosaga" : "cubelover");
}