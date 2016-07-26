#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int main(){
	char T[1000001], P[1000001];
	gets(T);
	gets(P);
	int N = strlen(T), M = strlen(P);
	if(N < M){
		puts("0");
		return 0;
	}

	int pi[1000000] = {0}, j = 0;
	for(int i=1; i<M; i++){
		while(j > 0 && P[i] != P[j]) j = pi[j-1];
		if(P[i] == P[j]) pi[i] = ++j;
	}

	vector<int> result;
	j = 0;
	for(int i=0; i<N; i++){
		while(j > 0 && T[i] != P[j]) j = pi[j-1];
		if(T[i] == P[j]){
			if(j == M-1){
				result.push_back(i-M+2);
				j = pi[j];
			}
			else j++;
		}
	}
	printf("%d\n", result.size());
	for(int val: result)
		printf("%d ", val);
}