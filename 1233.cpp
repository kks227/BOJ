#include <cstdio>
using namespace std;

int main(){
	int S1, S2, S3;
	scanf("%d %d %d", &S1, &S2, &S3);
	int cnt[81] = {0}, result = 0, max = 0;
	for(int i=1; i<=S1; i++)
		for(int j=1; j<=S2; j++)
			for(int k=1; k<=S3; k++)
				cnt[i+j+k]++;
	for(int i=0; i<=80; i++)
		if(max < cnt[i]){
			max = cnt[i];
			result = i;
		}
	printf("%d\n", result);
}