#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	int M, N;
	scanf("%d %d", &M, &N);
	bool p[1000001];
	memset(p, 1, sizeof(p));
	p[0] = p[1] = false;
	for(int i=4; i<=N; i+=2)
		p[i] = false;
	for(int i=3; i<1000; i+=2){
		if(!p[i]) continue;
		for(int j=i*i; j<=N; j+=i*2)
			p[j] = false;
	}
	for(int i=M; i<=N; i++)
		if(p[i]) printf("%d\n", i);
}