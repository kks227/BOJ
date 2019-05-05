#include <cstdio>
using namespace std;
const int MAX = 53;

int main(){
	int N, cnt[MAX] = {0,};
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		int A;
		scanf("%d", &A);
		++cnt[A];
	}
	getchar();
	for(int i = 0; i < N; ++i){
		char c = getchar();
		if(c == ' ') --cnt[0];
		else if(c <= 'Z') --cnt[c-'A'+1];
		else --cnt[c-'a'+27];
	}
	for(int i = 0; i < MAX; ++i){
		if(cnt[i] != 0){
			puts("n");
			return 0;
		}
	}
	puts("y");
}