#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int S[6], P[6], result[6] = {0};
		int s = 0;
		for(int i=0; i<6; i++){
			scanf("%1d", S+i);
			s = s*10 + S[i]-'0';
		}
		int cnt = 1e9;
		for(int i=1; i<10; i++){
			P[0] = P[5] = i;
			for(int j=0; j<10; j++){
				P[1] = P[4] = j;
				for(int k=0; k<10; k++){
					P[2] = P[3] = k;
					int p = 0;
					for(int i=0; i<6; i++)
						p = p*10 + P[i]-'0';
					int temp = abs(s-p);
					if(temp < cnt){
						cnt = temp;
						memcpy(result, P, sizeof(P));
					}
				}
			}
		}
		for(int i=0; i<6; i++)
			printf("%d", result[i]);
		puts("");
	}
}