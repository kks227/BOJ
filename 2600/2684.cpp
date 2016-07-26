#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	char S[8][4] = {"TTT", "TTH", "THT", "THH", "HTT", "HTH", "HHT", "HHH"};
	for(int t=0; t<T; t++){
		char C[41];
		scanf("%s", C);
		for(int i=0; i<8; i++){
			int cnt = 0;
			for(int j=0; j<38; j++)
				cnt += (S[i][0]==C[j] && S[i][1]==C[j+1] && S[i][2]==C[j+2]);
			printf("%d ", cnt);
		}
		puts("");
	}
}