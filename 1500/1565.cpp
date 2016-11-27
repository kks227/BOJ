#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
const int MAX = 1e9;
const int PMAX = 32000;

int GCD(int p, int q){
	while(q){
		int r = p % q;
		p = q;
		q = r;
	}
	return p;
}

long long LCM(int p, int q){
	return 1LL * p * q / GCD(p, q);
}

int main(){
	int M, N, A[50], B[50], G;
	long long L = 1;
	bool is0 = false;
	scanf("%d %d", &M, &N);
	for(int i=0; i<M; i++){
		scanf("%d", A+i);
		L = LCM(L, A[i]);
		if(L > MAX) is0 = true;
	}
	for(int i=0; i<N; i++){
		scanf("%d", B+i);
		G = (i ? GCD(G, B[i]) : B[i]);
	}
	if(is0 || G%L){
		puts("0");
		return 0;
	}

	bool isP[PMAX];
	memset(isP, 1, sizeof(isP));
	isP[0] = isP[1] = false;
	vector<int> p(1, 2);
	for(int i=4; i<PMAX; i+=2)
		isP[i] = false;
	for(int i=3; i<PMAX; i+=2){
		if(!isP[i]) continue;
		p.push_back(i);
		for(int j=i*i; j<PMAX; j+=i*2)
			isP[j] = false;
	}

	int K = G/L, result = 1;
	for(int i: p){
		int cnt = 0;
		while(K%i == 0){
			K /= i;
			cnt++;
		}
		result *= cnt+1;
	}
	if(K > 1) result *= 2;
	printf("%d\n", result);
}