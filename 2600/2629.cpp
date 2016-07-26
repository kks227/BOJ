#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int main(){
	int N, w[30];
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", w+i);

	bool s1[15001] = {true}, s2[15001];
	for(int i=0; i<N; i++){
		memset(s2, 0, sizeof(s2));
		for(int j=0; j<=15000; j++)
			if(s1[j]) s2[j] = s2[j+w[i]] = s2[(int)abs(j-w[i])] = true;
		memcpy(s1, s2, sizeof(s2));
	}

	int M;
	scanf("%d", &M);
	for(int i=0; i<M; i++){
		int dest;
		scanf("%d", &dest);
		printf("%c ", (dest <= 15000 && s1[dest]) ? 'Y' : 'N');
	}
}