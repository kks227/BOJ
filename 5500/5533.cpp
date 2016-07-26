#include <cstdio>
using namespace std;

int main(){
	int N, val[200][3], score[200] = {0};
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		for(int j=0; j<3; j++)
			scanf("%d", &val[i][j]);
	for(int i=0; i<3; i++){
		for(int j=0; j<N; j++){
			bool equal = false;
			for(int k=0; k<N; k++){
				if(j == k) continue;
				if(val[j][i] == val[k][i]){
					equal = true;
					break;
				}
			}
			if(!equal) score[j] += val[j][i];
		}
	}
	for(int i=0; i<N; i++)
		printf("%d\n", score[i]);
}