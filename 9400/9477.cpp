#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int N, B[30000];
long long S[30001], LS[30001], RS[30001];

long long PS(int start, int end, bool onRight){
	if(onRight) return LS[end]-LS[start] - (S[end]-S[start])*start;
	return RS[start]-RS[end] - (S[end]-S[start])*(N-end);
}

int main(){
	bool np[30000] = {0};
	np[0] = np[1] = true;
	vector<int> prime, possible;
	for(int i=4; i<30000; i+=2)
		np[i] = true;
	prime.push_back(2);
	for(int i=3; i<30000; i+=2){
		if(np[i]) continue;
		prime.push_back(i);
		for(int j=i*i; j<30000; j+=i)
			np[j] = true;
	}
	for(int i=3; i<29998; i+=2)
		if(!np[i] && !np[i+2]) possible.push_back(i);
	while(1){
		scanf("%d", &N);
		if(N == 0) break;
		memset(S, 0, sizeof(S));
		memset(LS, 0, sizeof(LS));
		memset(RS, 0, sizeof(RS));
		for(int i=0; i<N; i++){
			scanf("%d", B+i);
			S[i+1] = S[i] + B[i];
		}
		for(int i=0; i<N; i++){
			LS[i+1] = LS[i] + B[i]*(i+1);
			RS[N-i-1] = RS[N-i] + B[N-i-1]*(i+1);
		}
		
		long long result = 0x7FFFFFFFFFFFFFFF;
		for(int i=0; i<N; i++){
			// case 1: one stack
			result = min(result, PS(0, i, false) + PS(i+1, N, true));
			// case 2: two stacks (P)
			for(int j: prime){
				if(i+j >= N) break;
				result = min(result, PS(0, i, false) + PS(i+1+j, N, true) + PS(i+1, i+1+j/2, true) + PS(i+1+j/2, i+j, false));
			}
			// case 3: three stacks (2, P or P, 2)
			for(int j: possible){
				if(i+2+j >= N) break;
				result = min(result, PS(0, i, false) + PS(i+3+j, N, true) + PS(i+3, i+3+j/2, true) + PS(i+3+j/2, i+2+j, false) + B[i+1]);
				result = min(result, PS(0, i, false) + PS(i+3+j, N, true) + PS(i+1, i+1+j/2, true) + PS(i+1+j/2, i+j, false) + B[i+1+j]);
			}
			// case 4: four stacks (2, 3, 2)
			if(i+7 < N) result = min(result, PS(0, i, false) + PS(i+8, N, true) + B[i+1]+B[i+3]+B[i+4]+B[i+6]);
		}
		printf("%lld\n", result);
	}
}