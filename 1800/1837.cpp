#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int main(){
	char P[102];
	int K, L;
	scanf("%s %d", P, &K);
	L = strlen(P);
	vector<bool> isP(K, true);
	isP[0] = isP[1] = false;
	vector<int> prime(1, 2);
	for(int i=4; i<K; i+=2)
		isP[i] = false;
	for(int i=3; i<K; i+=2){
		if(!isP[i]) continue;
		prime.push_back(i);
		for(long long j=1LL*i*i; j<K; j+=i*2)
			isP[j] = false;
	}

	for(int p: prime){
		int m = 0, p10 = 1;
		for(int i=L-1; i>=0; i--){
			m = (m + (P[i]-'0')*p10) % p;
			p10 = p10 * 10 % p;
		}
		if(m == 0){
			printf("BAD %d\n", p);
			return 0;
		}
	}
	puts("GOOD");
}