#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		char N[1000001], M[1000001];
		scanf("%s %s", N, M);
		int cnt[2] = {0};
		for(int i=0; N[i]; i++)
			if(N[i] != M[i]) cnt[M[i]-'0']++;
		printf("%d\n", min(cnt[0], cnt[1]) + abs(cnt[0]-cnt[1]));
	}
}