#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, sum = 0;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		char S[4];
		int temp = 0;
		scanf("%s", S);
		for(int i = 0; S[i]; ++i){
			int d = S[i]-'0';
			if(d == 0 || d == 6) d = 9;
			temp = temp*10 + d;
		}
		sum += min(temp, 100);
	}
	printf("%.0lf\n", sum*1.0/N);
}