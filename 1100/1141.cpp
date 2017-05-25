#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	int N, result = 0;
	char W[50][51];
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%s", W[i]);
		for(int j=0; j<i; j++)
			if(strcmp(W[i], W[j]) == 0) W[j][0] = '\0';
	}
	for(int i=0; i<N; i++){
		if(!W[i][0]) continue;

		bool flag = true;
		for(int j=0; j<N; j++){
			if(i == j) continue;
			for(int k=0; W[j][k]; k++){
				if(!W[i][k]){
					flag = false;
					break;
				}
				if(W[i][k] != W[j][k]) break;
			}
			if(!flag) break;
		}
		if(flag) result++;
	}
	printf("%d\n", result);
}