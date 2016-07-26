#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	int N, M;
	scanf("%d", &N);
	char title[50][16];
	bool appear[50] = {0};
	for(int i=0; i<N; i++)
		scanf("%s", title[i]);
	scanf("%d", &M);
	int cnt = 0, result = -1;
	for(int i=0; i<M; i++){
		char lyrics[16];
		scanf("%s", lyrics);
		if(result != -1) continue;
		for(int j=0; j<N; j++){
			if(appear[j]) continue;
			if(strcmp(lyrics, title[j]) == 0){
				appear[j] = true;
				if(++cnt >= N/2.0) result = i+1;
				break;
			}
		}
	}
	printf("%d\n", result);
}