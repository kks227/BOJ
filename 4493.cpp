#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N, win[2] = {0};
		scanf("%d", &N);
		for(int i=0; i<N; i++){
			char A, B;
			getchar();
			scanf("%c %c", &A, &B);
			if(A=='R' && B=='S' || A=='S' && B=='P' || A=='P' && B=='R') win[0]++;
			else if(A=='R' && B=='P' || A=='P' && B=='S' || A=='S' && B=='R') win[1]++;
		}
		if(win[0] == win[1]) puts("TIE");
		else printf("Player %d\n", win[0]>win[1] ? 1 : 2);
	}
}