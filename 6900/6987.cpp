#include <cstdio>
using namespace std;

int val[6][3], dest[6][3], play[15][2];
bool result;

void backtrack(int pos){
	if(pos == 15){
		for(int i=0; i<6; i++)
			for(int j=0; j<3; j++)
				if(val[i][j] != dest[i][j]) return;
		result = true;
		return;
	}

	int a = play[pos][0], b = play[pos][1];
	val[a][0]++; val[b][2]++;
	backtrack(pos+1);
	val[a][0]--; val[b][2]--;
	val[a][2]++; val[b][0]++;
	backtrack(pos+1);
	val[a][2]--; val[b][0]--;
	val[a][1]++; val[b][1]++;
	backtrack(pos+1);
	val[a][1]--; val[b][1]--;
}

int main(){
	for(int i=0, k=0; i<5; i++){
		for(int j=i+1; j<6; j++, k++){
			play[k][0] = i;
			play[k][1] = j;
		}
	}
	for(int i=0; i<4; i++){
		for(int j=0; j<6; j++){
			for(int k=0; k<3; k++){
				scanf("%d", &dest[j][k]);
				val[j][k] = 0;
			}
		}
		result = false;
		backtrack(0);
		printf("%d ", result);
	}
}