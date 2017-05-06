#include <cstdio>
using namespace std;

int main(){
	int cnt[26] = {0}, pos[26][2], result = 0;
	for(int i=0; i<52; i++){
		int k = getchar() - 'A';
		pos[k][cnt[k]++] = i;
	}
	for(int i=0; i<26; i++)
		for(int j=0; j<26; j++)
			if(pos[i][0] < pos[j][0] && pos[j][0] < pos[i][1] && pos[i][1] < pos[j][1]) result++;
	printf("%d\n", result);
}