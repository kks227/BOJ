#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N;
		char O[100000];
		scanf("%d\n", &N);
		for(int i=0; i<N; i++)
			O[i] = getchar();
		
		int w2b = 0, b2w = 0;
		getchar();
		for(int i=0; i<N; i++){
			char c = getchar();
			if(O[i] == 'B' && c == 'W') w2b++;
			if(O[i] == 'W' && c == 'B') b2w++;
		}
		printf("%d\n", w2b+b2w - min(w2b, b2w));
	}
}