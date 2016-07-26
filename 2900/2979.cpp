#include <cstdio>
using namespace std;

int main(){
	int cost[3], cnt[100] = {0};
	for(int i=0; i<3; i++)
		scanf("%d", cost+i);
	for(int i=0; i<3; i++){
		int start, end;
		scanf("%d %d", &start, &end);
		for(int j=start; j<end; j++)
			cnt[j]++;
	}
	int result = 0;
	for(int i=0; i<100; i++)
		if(cnt[i]) result += cost[cnt[i]-1]*cnt[i];
	printf("%d\n", result);
}