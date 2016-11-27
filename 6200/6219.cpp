#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 4000000;

int main(){
	bool p[MAX+1] = {0};
	fill(p+2, p+MAX+1, true);
	for(int i=4; i<=MAX; i+=2)
		p[i] = false;
	for(int i=3; i<=MAX; i+=2){
		if(!p[i]) continue;
		if(1LL*i*i > MAX) continue;
		for(int j=i*i; j<=MAX; j+=i*2)
			p[j] = false;
	}

	int A, B, D, result = 0;
	scanf("%d %d %d", &A, &B, &D);
	for(int i=A; i<=B; i++){
		if(!p[i]) continue;
		bool flag = false;
		int n = i;
		while(n){
			if(n%10 == D){
				flag = true;
				break;
			}
			n /= 10;
		}
		result += flag;
	}
	printf("%d\n", result);
}