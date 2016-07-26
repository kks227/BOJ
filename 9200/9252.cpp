#include <cstdio>
#include <cstring>
using namespace std;

char S1[1001], S2[1001];
int len1, len2, cache[1000][1000], choose[1000][1000];

int LCS(int pos1, int pos2){
	if(pos1==len1 || pos2==len2) return 0;
	int &ret = cache[pos1][pos2];
	if(ret != -1) return ret;
	ret = LCS(pos1+1, pos2);
	int temp = LCS(pos1, pos2+1);
	if(ret < temp){
		ret = temp;
		choose[pos1][pos2] = 1;
	}
	else choose[pos1][pos2] = 0;
	if(S1[pos1] == S2[pos2]){
		temp = LCS(pos1+1, pos2+1)+1;
		if(ret < temp){
			ret = temp;
			choose[pos1][pos2] = 2;
		}
	}
	return ret;
}

void track(int pos1, int pos2){
	if(pos1==len1 || pos2==len2) return;
	switch(choose[pos1][pos2]){
	case 0:
		track(pos1+1, pos2);
		break;
	case 1:
		track(pos1, pos2+1);
		break;
	default:
		putchar(S1[pos1]);
		track(pos1+1, pos2+1);
	}
}

int main(){
	scanf("%s %s", S1, S2);
	len1 = strlen(S1);
	len2 = strlen(S2);
	memset(cache, -1, sizeof(cache));
	printf("%d\n", LCS(0, 0));
	track(0, 0);
}