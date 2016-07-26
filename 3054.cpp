#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	char word[16], S[5][66] = {0};
	int roff[8] = {-2, -1, -1, 0, 0, 1, 1, 2};
	int coff[8] = {0, -1, 1, -2, 2, -1, 1, 0};
	scanf("%s", word);
	int len = strlen(word);
	for(int i=0; i<5; i++)
		for(int j=0; j<len*4+1; j++)
			S[i][j] = '.';
	for(int i=0; i<len; i++){
		int r = 2, c = i*4+2;
		S[r][c] = word[i];
		if(i%3 == 2) continue;
		for(int j=0; j<8; j++)
			S[r+roff[j]][c+coff[j]] = '#';
	}
	for(int i=2; i<len; i+=3){
		int r = 2, c = i*4+2;
		for(int j=0; j<8; j++)
			S[r+roff[j]][c+coff[j]] = '*';
	}
	for(int i=0; i<5; i++)
		puts(S[i]);
}