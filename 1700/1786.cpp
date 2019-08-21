#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int MAX = 1000000;
const int MAX_T = 1000000;

int main(){
	char S[MAX+1], T[MAX_T+1];
	gets(S);
	gets(T);
	int N = strlen(S), M = strlen(T);

	int p[MAX_T] = {0};
	for(int i = 1, j = 0; i < M; ++i){
		while(j > 0 && T[i] != T[j]) j = p[j-1];
		if(T[i] == T[j]) p[i] = ++j;
	}
	vector<int> result;
	for(int i = 0, j = 0; i < N; ++i){
		while(j > 0 && S[i] != T[j]) j = p[j-1];
		if(S[i] == T[j]){
			if(j == M-1){
				result.push_back(i-M+2);
				j = p[j];
			}
			else j++;
		}
	}
	printf("%d\n", result.size());
	for(int i: result)
		printf("%d ", i);
}