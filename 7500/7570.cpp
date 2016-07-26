#include <cstdio>
#include <algorithm>
using namespace std;

int row[1000000];
int pos[1000001];

int main(){

	int N;
	int result = 0, cnt;

	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", row+i);
		pos[row[i]] = i;
	}

	cnt = 1;
	for(int i=1; i<N; i++){
		if(pos[i-1] < pos[i]) cnt++;
		else{
			result = max(result, cnt);
			cnt = 1;
		}
	}
	result = max(result, cnt);
	printf("%d\n", N - result);

	return 0;
}